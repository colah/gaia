#ifndef SIMULATION_H
#define SIMULATION_H

#include "Tile.h"

#include <Planet.h>

/** Objects of the Planet class represent a planet in the simulation.
  * It organizes all the tiles (Tile ), provides a mechanism 
  * to access them ([] ), and functions to modify the planet.

 * @section tiles
 * @subsection 2dArray 
 * How Tiles are organized into m_tiles, relative to the variable precision (represented by p):

 * <pre>                            longitude
 *                  ________________________________
 *                 |(-2p,p)  ... (0,p)  ... (2p,p) |
 *                 |   ...         ...       ...   |
 *     latitude    |(-2p,0)  ... (0,0)  ... (2p,0) |
 *                 |   ...         ...       ...   |
 *                 |(-2p,-p) ... (0,-p) ... (2p,-p)|
 *                 |_______________________________|   </pre>

 *   @note In terms of radians, \f$ p=\pi/2 \f$.
 *   @note The operator [] is then overloaded for this class to allow for
 * (*this)[latitude][longitude] 
 * @subsection 1dArray
 * The orginization doubles, however. Not only are the tiles in a 2d array,
 * they're also in a 1d array:
 * <pre> |latitude|latitude|... longitude times.</pre>
*/

class Simulation : public Marble::Planet
{
public:
	/** Planet Constructor. It generates all tiles, with appropriate area, etc.
	  * @param precision the number of tiles to create per pi/2 radians.
	  * @param planet the planet to be simulated
	  */
	Simulation( int precision, const Marble::Planet* planet);

	/** Returns the Tile at a given latitude and longitude.
	  * @param lat latitude in Radians
	  * @param lon longitude in Radians */
	Tile * getAtLL(double lon, double lat);

	/**Smite the planet with a comet!
	  *@param lon longitude
	  *@param lat latitude*/
	void comet(double lon, double lat);

	/**causes erosion*/
	void erode();

private:
	/**  m_tiles is a 2d array of Tiles.*/
	Tile **m_tiles;
	/** describes the precision of the simulation and by extension
	the dimensions of m_tiles. */
	int  m_precision;
	int maxX,maxY;
	///FIXME: Needs a more descriptive name than PtoR
	double PtoR;
	 /*
	 * Diagram
	 * How Tiles are organized into m_tiles, relative to the variable
	 * m_precision (represented by p):
	 *                            longitude
	 *                  ________________________________
	 *                 |(-2p,p)  ... (0,p)  ... (2p,p) |
	 *                 |   ...         ...       ...   |
	 *     latitude    |(-2p,0)  ... (0,0)  ... (2p,0) |
	 *                 |   ...         ...       ...   |
	 *                 |(-2p,-p) ... (0,-p) ... (2p,-p)|
	 *                 |_______________________________|
	 *
	 *  NOTE In terms of radians,  p=π/2 .
	 *
	 *  NOTE The operator [] is then overloaded for this class to allow for
	 * (*this)[latitude][longitude]                                              */

	/*General Data*/
	/** The planet's mass in kg.*/
	double m_mass;
	/** The radius of the non-negligible atmosphere's radius in m. */
	double m_atmosphericRadius;
};

#endif


