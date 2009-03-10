
#ifndef THERMOSPHERE_H
#define THERMOSPHERE_H

#include "TileLayer.h"

/**The thermosphere is the main part of the atmosphere of a planet.*/
class Thermosphere: public TileLayer
{
public:
	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	Thermosphere();

};

#endif


