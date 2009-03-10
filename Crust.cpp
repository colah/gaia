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

void Crust::setFirmness( double firmness )
{
	return m_firmness;
}

void Crust::setRoughness( double roughness )
{
	return m_roughness;
}

void Crust::setBaseHeight( double baseHeight )
{
	return m_baseHeight;
}
