

//Own header
#include "Simulation.h"

//Marble Includes
#include <marble/Planet.h>
#include <marble/GeoDataCoordinates.h>

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
	for (int x = -m_precision*2; x <= m_precision*2; ++x) {
		/*Make an array for each, and phase shift it. */
		m_tiles[x]  = new Tile[m_precision*4 + 1];
		m_tiles[x] += m_precision*2;
	}
	
	for (int x = -m_precision*2; x <= m_precision*2; ++x) {
		for (int y = -m_precision; y <= m_precision; ++y) {
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
			m_tiles[x][y].crust().area  = 4*M_PI*M_PI*pow(radius(),2.0);
			m_tiles[x][y].crust().area *= fabs( sin(PtoR*(x+0.5)) - sin(PtoR*(y-0.5)) );
			m_tiles[x][y].crust().area /= PtoR;
			/** @todo fix the following, they're written to quickly avoid segfaults, but they really need to be done differently: with polar wrap around.*/
			if       (x == -m_precision*2){
				m_tiles[x][y].south( &m_tiles[x][y]);
				m_tiles[x][y].north( &m_tiles[++x][y]);
			}else if (x ==  m_precision*2){
				m_tiles[x][y].south( &m_tiles[--x][y]);
				m_tiles[x][y].north( &m_tiles[x][y]);
			}else                         {
				m_tiles[x][y].south( &m_tiles[--x][y]);
				m_tiles[x][y].north( &m_tiles[++x][y]);

			}

			if       (y == -m_precision  ){
				m_tiles[x][y].east(&(m_tiles[x][++y]));
				m_tiles[x][y].west(&(m_tiles[x][--y]));
			}else if (y ==  m_precision  ){
				m_tiles[x][y].east( &(m_tiles[x][++y]));
				m_tiles[x][y].west( &(m_tiles[x][--y]));
			}else                         {
				m_tiles[x][y].east( &(m_tiles[x][++y]));
				m_tiles[x][y].west( &(m_tiles[x][--y]));
			}

			m_tiles[x][y].planet = this;
			m_tiles[x][y].crust.base_height = 0;
		}
	}
}

void Simulation::comet(double lat, double lon)
{
	Tile *test = getAtLL(lat,lon);
	test->crust().baseHeight() += 5/test->crust().area();
}

