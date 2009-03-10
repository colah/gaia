#ifndef CRUST_H
#define CRUST_H

#include "TileLayer.h"

/**The Crust is the outermost solid layer of a planet.*/
class Crust : public TileLayer
{
public:
	Crust( double firmness, double roughness, double baseHeight );

	/** Get the resistance to erosion.
	@return the firmness (in what? Some coefficient?)
	@see setFirmness()
	*/
	double firmness() const;

	/** The value that represents the "roughness" of terrain: hills, valleys etc.
	@return the roughness (in what? @see firmness() )
	@see setRoughness()
	*/
	double roughness() const;

	/** The height in m from radius.
	@return the height of the (top/bottom)? of the crust
	@see setBaseHeight()
	*/
	double baseHeight() const;

	/** Sets the firmness.
	@param firmness the new firmness
	@see firmness()
	*/
	void setFirmness( double firmness );

	/** Sets the roughness.
	@param roughness the new roughness
	@see roughness()
	*/
	void setRoughness( double roughness );

	/** Sets the base height of the terrain
	@param baseHeight
	@see baseHeight()
	*/
	void setBaseHeight( double baseHeight );

private:
	double m_firmness, m_roughness, m_baseHeight;
};

#endif