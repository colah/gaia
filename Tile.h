#ifndef TILE_H
#define TILE_H


#include "InnerCore.h"
#include "OuterCore.h"
#include "Mantle.h"
#include "Crust.h"
#include "Troposphere.h"
#include "Thermosphere.h"
#include "Simulation.h"


/**
 * An object of Tile represents a certain amount of space on the gloce. This space
 * goes from the edge of the atmosphere to the inner core. Not all objects of Tile
 * occupy the same area (it depends on longitude and latitude).
 * Thus, where possible
 * measurements are in m \f$^2 \f$.
 * 
 * @section Layers
 *<pre>
 * ___________________________________________________________________________
 *|   PART      |   NAME    |  DESCRIPTION                                    |
 *|_____________|___________|_________________________________________________|
 *|              _
 *| Atmosphere: | Thermosphere: Different chemical composition due to gass mass.
 *|             |               GHGs and ozone. Main atmospheric component.
 *|             | Troposphere:  From crust to reasonable hight. It is chemicaly
 *|             |_             consistant due to convection.
 *|              _
 *|             |  Crust:       Surface.
 *| Solid:      |  Mantle:      Majority of solid planet.
 *|             |  OuterCore:  Hot; Liquid; molten.
 *|             |_ InnerCore:  Hot; solid and dense due to pressure.
 *|___________________________________________________________________________</pre>
 * 
 * @note: The names of planetary layers are capitalized so that we can have their
 * lower case in Tiles. This concept is actually aplied in other cases, as well.   */
class Tile
{
public:
	/** The ID of the tile
	@return the unique tile identifier
	*/
	unsigned int id() const;

	/*General Things */

	/** The parent of this tile: its simulation
	@return a pointer to the simulation which owns this tile
	*/
	Simulation* simulation() const;

	/** The tile to the north of this one
	@return a pointer to the tile to the north of this one
	*/
	Tile* north() const;

	/** The tile to the south of this one
	@return a pointer to the tile to the south of this one
	*/
	Tile* south() const;

	/** The tile to the east of this one
	@return a pointer to the tile to the east of this one
	*/
	Tile* east() const;

	/** The tile to the west of this one
	@return a pointer to the tile to the west of this one
	*/
	Tile* west() const;

	/** Set the tile to the north of this one */
	void north(Tile *newNorth) const;

	/** Set the tile to the south of this one */
	void south(Tile *newSouth) const;

	/** Set the tile to the east of this one */
	void east(Tile *newEast) const;

	/** Set the tile to the west of this one */
	void west(Tile *newWest) const;

	/** The longitude of this tile.
	@note In formulas, longitude is \f$ \lambda \f$
	@return the longitude (in the centre?)
	*/
	double lon() const;

	/** The latitude of this tile.
	@note In formulas, latitude is \f$ \phi \f$
	@return the latitude (in the centre?)
	*/
	double lat() const;

	/** The area at average planetary radius, in m \f$^2 \f$
	@note everything else should be in terms of density, e.g.
	moles * m \f$^{-2} \f$
	@return the area of this tile
	*/
	double area();

	/** The Thermosphere at this Tile
	@return a reference to the thermosphere
	*/
	Thermosphere& thermosphere() const;
	/** The Troposphere at this Tile
	@return a reference to the troposphere
	*/
	Troposphere& troposphere() const;
	/** The Crust at this Tile
	@return a reference to the crust
	*/
	Crust& crust() const;
	/** The Mantle at this Tile
	@return a reference to the mantle
	*/
	Mantle& mantle() const;
	/** The OuterCore at this Tile
	@return a reference to the outer core
	*/
	OuterCore& outerCore() const;
	/** The InnerCore at this Tile
	@return a reference to the inner core
	*/
	InnerCore& innerCore() const;

private:
	unsigned int m_id;
	Simulation *m_simulation;
	Tile* m_north, m_south, m_east, m_west;
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


