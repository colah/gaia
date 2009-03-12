#include "Crust.h"

Crust::Crust( double firmness, double roughness, double elevation, Tile* parent)
	: TileLayer(parent)
{
	m_firmness = firmness;
	m_roughness = roughness;
	m_elevation = elevation;
}

Crust::Crust()
{
}

double Crust::firmness() const
{
	return m_firmness;
}

double Crust::roughness() const
{
	return m_roughness;
}

double Crust::elevation() const
{
	return m_elevation;
}

double Crust::area() const
{
	return m_area;
}

void Crust::setFirmness( double firmness )
{
	m_firmness = firmness;
}

void Crust::setRoughness( double roughness )
{
	m_roughness = roughness;
}

void Crust::setElevation( double elevation )
{
	m_elevation = elevation;
}

void Crust::setArea(double area)
{
	m_area = area;
}


