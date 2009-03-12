#ifndef OUTERCORE_H
#define OUTERCORE_H

#include "TileLayer.h"

/** The Outer Core is the hot liquid near-center of a planet.*/
class OuterCore : public TileLayer
{
public:
	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	OuterCore();

	/** Constructor
	@param parent the parent tile
	*/
	OuterCore( Tile *parent );
};

#endif

