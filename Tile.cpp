//Own includes
#include "Tile.h"

//Gaia includes
#include "InnerCore.h"
#include "OuterCore.h"
#include "Mantle.h"
#include "Crust.h"
#include "Troposphere.h"
#include "Thermosphere.h"
#include "Simulation.h"

#include <cstdlib>
#include <cmath>
using std::rand;
using std::pow;
using std::sin;
using std::fabs;

Tile::Tile( double lon, double lat, double area, Simulation *parent )
{
	m_id = rand();
	m_lat = lat;
	m_lon = lon;
	m_area = area;
	m_simulation = parent;
}

Tile::Tile()
{
}

Tile::Tile(int x, int y, Simulation *parent){
	m_simulation = parent;
	double PtoR = parent->PtoR;

	m_x = x; m_y = y;

	/** @note On a perfect sphere, the formula for area is:
	* \f$ \frac{4\pi^2r^2 \lvert\sin(\phi_1)-\sin(\phi_2)\rvert }
	* {\lvert \lambda_2-\lambda_1 \rvert} \f$*/
	//OR, in plaintext:
	/*       4π²r²|sin(φ_1)-sin(φ_2)|        *
	  * a  =  ------------------------        *
	  *            |λ_2 - λ_1|                */
	m_area  = 4*M_PI*M_PI*pow(simulation()->radius(),2.0);
	m_area *= fabs( sin(PtoR*(x+0.5)) - sin(PtoR*(y-0.5)) );
	m_area /= PtoR;
	
	
	  /** @todo fix the following, they're written to quickly avoid segfaults, but they 
	    * really need to be done differently: with polar wrap around.
	    * @note this is written using simple pointer arithmetic. Remember: n+i = &n[i], 
	    * but n+i is faster.*/
	  //NOTE: perhaps this should be in another function? --h
	  //If you want to look at one correct implementation of normalization
	  //try looking at Marble::GeoDataCoordinates::normalizeLonLat
	  //(it took me several tries to get it right)
	  //Chris: I will, later. This is just a hacky solution.
}



Simulation* Tile::simulation() const
{
	return m_simulation;
}

double Tile::lon() const
{
	/* We want to have longitude and latitude measured in radians,*
	 * not our array indices.                                     */
	return m_x*parent->PtoR;
}

double Tile::lat() const
{
	/* We want to have longitude and latitude measured in radians,*
	 * not our array indices.                                     */
	return m_y*parent->PtoR;
}

double Tile::area() const
{
	return m_area;
}

Thermosphere& Tile::thermosphere()
{
	return m_thermosphere;
}

Troposphere& Tile::troposphere()
{
	return m_troposphere;
}

Crust& Tile::crust()
{
	return m_crust;
}

Mantle& Tile::mantle()
{
	return m_mantle;
}

OuterCore& Tile::outerCore()
{
	return m_outerCore;
}

InnerCore& Tile::innerCore()
{
	return m_innerCore;
}

void erode()
{
	///@todo Implement me!
}



