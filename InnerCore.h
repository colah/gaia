#ifndef INNERCORE_H
#define INNERCORE_H

#include "TileLayer.h"

/** The Inner Core is the hot, very dense center of a planet.*/
class InnerCore : public TileLayer
{
public:
	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	InnerCore();
	
	/** Constructor
	@param parent the parent tile
	*/
	InnerCore( Tile *parent );
};

#endif

