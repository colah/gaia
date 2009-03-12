
#ifndef TROPOSPHERE_H
#define TROPOSPHERE_H

#include "TileLayer.h"
/**The thermosphere is the main part of the atmosphere of a planet.*/
class Troposphere : public TileLayer
{
public:
	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	Troposphere();
	/** Constructor
	@param parent the parent tile
	*/
	Troposphere( Tile *parent );
};

#endif

