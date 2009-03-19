

//Own header
#include "Simulation.h"

//Qt includes
#include <QtCore/QSize>
#include <QtCore/QList>
#include <QtCore/QDebug>

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
	//The array has 0,0 at -π, π/2, so we adjust the coords
	//set -π = 0
	lon += M_PI;
	//set π/2 = 0
	lat = fabs( lat - (M_PI/2.0) );
	lat /= m_PtoR;
	lon /= m_PtoR;
	int x = static_cast<int>(floor(lon));
	int y = static_cast<int>(floor(lat));
	//qDebug() << "getAtLL: convert LL" << lon << lat << "to ints" << x << y;
	return m_tiles[x][y];
}

Simulation::Simulation( int precision, const Planet* planet )
	: Planet(*planet),
	m_precision(precision),
	m_PtoR( M_PI /m_precision ),
	m_size( 2*precision, precision )
{
	//Construct our list of lists
	m_tiles = QList< QList<Tile*> >();
	//By using X first we can do m_tiles[x][y]->foo()
	for( int x = 0; x < m_size.width(); ++x ) {
		//Append a list for this column
		m_tiles.push_back( QList<Tile*>() );
		for( int y = 0; y < m_size.height(); ++y ) {
			//Create a new tile
			Tile *t = new Tile(x,y,this);
			//Add it to the array
			m_tiles[x].push_back( t );
		}
	}
}

void Simulation::comet(double lon, double lat)
{
	Tile *test = getAtLL(lon,lat);
	Crust c = test->crust();
	c.setElevation( (5.0/ test->area()) + c.elevation() );
}

double Simulation::PtoR() const
{
	return m_PtoR;
}

QSize Simulation::arraySize() const
{
	return m_size;
}

void Simulation::erode()
{
	for( int x = 0; x < m_size.width(); ++x ) {
		for( int y = 0; y < m_size.height(); ++y ) {
			//Erode the tile
			m_tiles[x][y]->erode();
		}
	}
}
