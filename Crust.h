#ifndef CRUST_H
#define CRUST_H

#include "TileLayer.h"

/**The Crust is the outermost solid layer of a planet.*/
class Crust : public TileLayer
{
public:
	/** Crust constructor
	@param firmness the firmness. @see firmness()
	@param roughness the roughness. @see roughness()
	@param baseHeight the baseHeight. @see baseHeight()
	*/
	Crust( double firmness, double roughness, double baseHeight );
	
	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	Crust();

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

	/** The surface area of the planet at the Crust
	  * @return the area in m^2
	  * @see setArea()
	*/
	double area() const;

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

	/** Sets the surface area of the planet at the Crust
	  * @param area the area in m^2
	  * @see area()
	*/
	void setArea(double area);

private:
	double m_firmness, m_roughness, m_baseHeight, m_area;
};

#endif