

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
	//Lon/Lat have to be normalized together, or it'll be done wrong.
	GeoDataCoordinates::normalizeLonLat( lon, lat );
	lat /= PtoR;
	lon /= PtoR;
	return m_tiles[(int)ceil(lat - 0.5)]+(int)ceil(lon-0.5);
}

Simulation::Simulation( int precision, Planet planet )
	: Planet(planet), m_precision(precision)
{
	PtoR = (M_PI/2)/m_precision;

	maxX = m_precision*2; maxY = m_precision;
	/*Make the array of arrays, and phase shift it. */
	m_tiles     = new Tile*[maxX*2+1];
	m_tiles    += maxX;
	/*Make the array of tiles.*/
	Tile *array = new Tile[(maxX*2 + 1)*(maxY*2 + 1)];
	/*Make each pointer to an array in m_tiles point to a point in
	 * our Tile array such that it is at the midle of a subarray of
	 * length m_precision*4 + 1.*/
	for (int x = -maxX; x <= maxX; ++x) {
		m_tiles[x]  = array;
		m_tiles[x] += x*(maxY*2 + 1);
		m_tiles[x] += maxY;
	}
	/*Create each Tile.*/
	for (int x = -maxX; x <= maxX; ++x) {
		for (int y = -maxY; y <= maxY; ++y) {
			m_tiles[x][y] = Tile(x,y,this);
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
	//It would be cool to use pointer arithmetic to do an iterator style loop.
	//More efficient too.
	///@todo fix elevation only leans north. Consider our API, I think the OO encapsulation has been taken a little to far.
	
	for (int x = -maxX; x <= maxX; ++x) {
		for (int y = -maxY; y <= maxY; ++y) {
			tiles[x][y].erode();
		}
	}

}
