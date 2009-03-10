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
using std::rand;

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

Simulation* Tile::simulation() const
{
	return m_simulation;
}

Tile* Tile::north() const
{
	return m_north;
}

Tile* Tile::south() const
{
	return m_south;
}

Tile* Tile::east() const
{
	return m_east;
}

Tile* Tile::west() const
{
	return m_west;
}

void Tile::setNorth(Tile *newNorth)
{
	m_north = newNorth;
}

void Tile::setSouth(Tile *newSouth)
{
	m_south = newSouth;
}

void Tile::setEast(Tile *newEast)
{
	m_east = newEast;
}

void Tile::setWest(Tile *newWest)
{
	m_west = newWest;
}

double Tile::lon() const
{
	return m_lon;
}

double Tile::lat() const
{
	return m_lat;
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

