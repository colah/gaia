#include <cmath>

#include "Tile.cpp"

/** Objects of the Planet class represent a planet in the simulation.
  * It organises all the tiles (Tile ), provides a mechanisms 
  * to access them ([] ), and functions to modify the planet.

 * @section Diagram 
 * How Tiles are organized into tiles, relative to the variable precision (represented by p):

 * <pre>                            longitude
 *                  ________________________________
 *                 |(-2p,p)  ... (0,p)  ... (2p,p) |
 *                 |   ...         ...       ...   |
 *     latitude    |(-2p,0)  ... (0,0)  ... (2p,0) |
 *                 |   ...         ...       ...   |
 *                 |(-2p,-p) ... (0,-p) ... (2p,-p)|
 *                 |_______________________________|   </pre>

 *   @note In terms of radiens, \f$ p=\pi/2 \f$.
 *   @note The operator [] is then overloaded for this class to allow for
 * (*this)[latitude][longitude]                                             */

class Planet{
	public:

	Tile **tiles; 	/**<  tiles is a 2d array of Tiles.*/

	int  percision;	 /**< describes the percision of the simulation and by extention the dimensions of tiles. */
	 /*
	 * Diagram 
	 * How Tiles are organized into tiles, relative to the variable precision (represented by p):

         *                            longitude
	 *                  ________________________________
	 *                 |(-2p,p)  ... (0,p)  ... (2p,p) |
	 *                 |   ...         ...       ...   |
	 *     latitude    |(-2p,0)  ... (0,0)  ... (2p,0) |
	 *                 |   ...         ...       ...   |
	 *                 |(-2p,-p) ... (0,-p) ... (2p,-p)|
	 *                 |_______________________________|
	 *
         *   NOTE In terms of radiens,  p=π/2 .
	 *
	 *  NOTE The operator [] is then overloaded for this class to allow for
	 * (*this)[latitude][longitude]                                              */

	/*General Data*/
	double mass;               /**< The planet's mass in kg.*/
	double radius;             /**< The average radius of the solid, 'land' part of the planet in m.*/
	double atmospheric_radius; /**< The radius of the non-negligble atmosphere's radius in m. */

	/** Returns the Tile at a given latitude and longitude.
	  * @param lat latitude in Radiens
	  * @param lon longiutde in Radiens */
	Tile getAtLL(double lat, double lon){
		double PtoR = M_PI/2/this->percision;
		lat  /= PtoR;
		lon /= PtoR;
		return tiles[ceil(lat - 0.5)][ceil(lon-0.5)];
	}

	/** Planet Constructor. It generates all tiles, with apropriate area, etc.
	  * @param lpercision an integer that describes percision.
	  * @param r  the radius of the planet.          */
	Planet (int lpercision, double r){

		this->percision = lpercision;
		double PtoR = M_PI/2/this->percision;
		this->radius = r;
		/*Make the array of arrays, and phase shift it. */
		this->tiles  =  new Tile*[this->percision*2 + 1];
		this->tiles += this->percision;
		for (int i = -this->percision; i <= this->percision; ++i){
			/*Make an array for each, and phase shift it. */
			this->tiles[i]  = new Tile[this->percision*4+1];
			this->tiles[i] += this->percision*2;
		}
		for (int i = -this->percision; i <= this->percision; ++i){
			for (int j = -this->percision*2; j <= this->percision*2; ++j){
				/*We want to have longitude in latitude measured in radiens,  *
				 * not our array indeces.                                     */
				this->tiles[i][j].latitude  = i*PtoR;
				this->tiles[i][j].longitude = j*PtoR;

				 /** @note On a perfect sphere, the formula for area is:
				 * \f$ \frac{4\pi^2r^2 \lvert\sin(\phi_1)-\sin(\phi_2)\rvert }{\lvert \lambda_2-\lambda_1 \rvert} \f$*/
				 /*       4π²r²|sin(φ_1)-sin(φ_2)|        *
				  * a  =  ------------------------        *
				  *            |ƛ_1 - ƛ_2|                */
				this->tiles[i][j].crust.area = 4*pow(M_PI,2)*pow(this->radius,2)*fabs(sin(PtoR*(i+0.5))-sin(PtoR*(i-0.5)))/PtoR;

				this->tiles[i][j].south = this->tiles[i-1][j];
				this->tiles[i][j].north = this->tiles[i+1][j];
				this->tiles[i][j].east = this->tiles[i][j+1];
				this->tiles[i][j].west = this->tiles[i][j-1];

				this->tiles[i][j].planet = this;

				
			}
		}
	}


};

int main(){
	Planet *planet = new Planet(100, 6e9);
	return 0;

}

