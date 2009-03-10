#include "Crust.h"

Crust::Crust( double firmness, double roughness, double baseHeight )
{
	m_firmness = firmness;
	m_roughness = roughness;
	m_baseHeight = baseHeight;
}

double Crust::firmness() const
{
	return m_firmness;
}

double Crust::roughness() const
{
	return m_roughness;
}

double Crust::baseHeight() const
{
	return m_baseHeight;
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

void Crust::setBaseHeight( double baseHeight )
{
	m_baseHeight = baseHeight;
}

void Crust::setArea(double area)
{
	m_area = area;
}
