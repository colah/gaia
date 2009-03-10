

//Own header
#include "Simulation.h"

//Marble Includes
#include <Planet.h>
#include <GeoDataCoordinates.h>

//Math Includes
#include <cmath>

//Gaia Includes
#include "Tile.h"

using namespace std;
using namespace Marble;

Tile * Simulation::getAtLL(double lon, double lat)
{
	//FIXME: Needs a more descriptive name than PtoR
	double PtoR = (M_PI/2)/m_precision;
	//Lon/Lat have to be normalized together, or it'll be done wrong.
	GeoDataCoordinates::normalizeLonLat( lon, lat );
	lat /= PtoR;
	lon /= PtoR;
	return m_tiles[(int)ceil(lat - 0.5)]+(int)ceil(lon-0.5);
}

Simulation::Simulation( int precision, Planet planet )
	: Planet(planet), m_precision(precision)
{
	double PtoR = (M_PI/2)/m_precision;
	/*Make the array of arrays, and phase shift it. */
	m_tiles  =  new Tile*[m_precision*2 + 1];
	m_tiles += m_precision;
	maxX = m_precision*2;
	maxY = m_precision;
	//for (int x = -maxX; x <= maxX; ++x) {}
	
	for (int x = -maxX; x <= maxX; ++x) {
		for (int y = -maxY; y <= maxY; ++y) {
			/* We want to have longitude and latitude measured in radians,*
			 * not our array indices.                                     */
			double lon = x*PtoR;
			double lat = y*PtoR;
			
			/** @note On a perfect sphere, the formula for area is:
			* \f$ \frac{4\pi^2r^2 \lvert\sin(\phi_1)-\sin(\phi_2)\rvert }
			           {\lvert \lambda_2-\lambda_1 \rvert} \f$*/
			//OR, in plaintext:
			/*       4π²r²|sin(φ_1)-sin(φ_2)|        *
			 * a  =  ------------------------        *
			 *            |λ_2 - λ_1|                */
			double area  = 4*M_PI*M_PI*pow(radius(),2.0);
			area *= fabs( sin(PtoR*(x+0.5)) - sin(PtoR*(y-0.5)) );
			area /= PtoR;

			m_tiles[x][y] = Tile( lon, lat, area, this );
			
			/** @todo fix the following, they're written to quickly avoid segfaults, but they really need to be done differently: with polar wrap around.*/
			//NOTE: perhaps this should be in another function? --h
			//If you want to look at one correct implementation of normalization
			//try looking at Marble::GeoDataCoordinates::normalizeLonLat
			//(it took me several tries to get it right)
			if       (x == -m_precision*2){
				m_tiles[x][y].setSouth( &m_tiles[x][y]);
				m_tiles[x][y].setNorth( &m_tiles[++x][y]);
			}else if (x ==  m_precision*2){
				m_tiles[x][y].setSouth( &m_tiles[--x][y]);
				m_tiles[x][y].setNorth( &m_tiles[x][y]);
			}else                         {
				m_tiles[x][y].setSouth( &m_tiles[--x][y]);
				m_tiles[x][y].setNorth( &m_tiles[++x][y]);
			}

			if       (y == -m_precision  ){
				m_tiles[x][y].setEast(&(m_tiles[x][++y]));
				m_tiles[x][y].setWest(&(m_tiles[x][--y]));
			}else if (y ==  m_precision  ){
				m_tiles[x][y].setEast( &(m_tiles[x][++y]));
				m_tiles[x][y].setWest( &(m_tiles[x][--y]));
			}else                         {
				m_tiles[x][y].setEast( &(m_tiles[x][++y]));
				m_tiles[x][y].setWest( &(m_tiles[x][--y]));
			}
			//FIXME: give actual values
			m_tiles[x][y].crust() = Crust( 1, 1, 0 );
		}
	}
}

void Simulation::comet(double lat, double lon)
{
	Tile *test = getAtLL(lat,lon);
	Crust c = test->crust();
	c.setElevation( (5.0/ test->area()) + c.elevation() );
}

void erode(){
	//It would be cool to use pointer arithmetic to do an iterator style loop. More efficient to.
	///@todo fix elevation only leans north. Consider our API, I think the OO encapsulation has been taken a little to far.
	double Delta;
	for (int x = -maxX; x <= maxX; ++x) {
		for (int y = -maxY; y <= maxY; ++y) {
			Delta = tiles[x][y].north().crust().elevation() - tiles[x][y].crust().elevation();
			if (Delta > 0) {
				tiles[x][y].crust().setElevation(
					  tiles[x][y].crust().elevation() 
					+ Delta
					    *tiles[x][y].crust().roughness()
					    /tiles[x][y].crust().elevation().firmness());
				tiles[x][y].crust().setElevation(
					  tiles[x][y].north().crust().elevation() 
					+ Delta
					    *tiles[x][y].north().crust().roughness()
					    /tiles[x][y].north().crust().elevation().firmness());
			}
		}
	}

}
