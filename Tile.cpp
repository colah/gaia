#include "Tile.h"

Tile::Tile( double lon, double lat, double area, Simulation *parent )
{
	m_lat = lat;
	m_lon = lon;
	m_area = area;
	m_simulation = parent;
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

void north(Tile *newNorth) const
{
	m_north = newNorth;
}

void south(Tile *newSouth) const
{
	m_south = newSouth;
}

void east(Tile *newEast) const
{
	m_east = newEast;
}

void west(Tile *newWest) const
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

Thermosphere& Tile::thermosphere() const
{
	return m_thermosphere;
}

Troposphere& Tile::troposphere() const
{
	return m_troposphere;
}

Crust& Tile::crust() const
{
	return m_crust;
}

Mantle& Tile::mantle() const
{
	return m_mantle;
}

OuterCore& Tile::outerCore() const
{
	return m_outerCore;
}

InnerCore& Tile::innerCore() const
{
	return m_innerCore;
}

#if 0
private:
	uint m_id
{
	
}
	Simulation *m_simulation
{
	
}
	Tile* m_north, m_south, m_east, m_west
{
	
}
	double m_lon, m_lat;
	double m_area;
	//Layers:
	Thermosphere m_thermosphere;
	Troposphere m_troposphere;
	Crust m_crust;
	Mantle m_mantle;
	OuterCore m_outerCore;
	InnerCore m_innerCore;
};
#endif



