#ifndef TILE_H
#define TILE_H

#include <QtCore/QList>
#include <QtCore/QPoint>

#include "InnerCore.h"
#include "OuterCore.h"
#include "Mantle.h"
#include "Crust.h"
#include "Troposphere.h"
#include "Thermosphere.h"

//typedef unsigned int uint;

class Simulation;

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
	/** Tile Constructor
	@param lon the longitude of this tile (in the centre? at a corner?)
	@param lat the latitude of this tile (in the centre? at a corner?)
	@param area the area of this tile
	@param parent the parent simulation
	*/
	//Tile( double lon, double lat, double area, Simulation *parent );

	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	Tile();

	/** Constructor
	 * @param x position on x axis in simulation array.
	 * @param y position on y axis in simulation array.
	 * @param parent the parent simulation
	*/
	Tile(int x, int y, Simulation *parent);

	/** Constructor
	 * @param x position on x axis in simulation array.
	 * @param y position on y axis in simulation array.
	 * @param parent the parent simulation
	 * @todo There's no reason for it to need area. It knows lon/lat.
	*/
	Tile( double lon, double lat, double area, Simulation *parent );

	/** The ID of the tile
	@return the unique tile identifier
	*/
	uint id() const;

	/*General Things */

	/** The parent of this tile: its simulation
	@return a pointer to the simulation which owns this tile
	*/
	Simulation* simulation() const;

	/** Get this tile's location on the 2D array
	 * @return the tile's location on the 2D array
	 */
	QPoint loc() const;

	/** Get this tile's neighbours
	 * @return a list of this tile's neighbours
	 */
	QList<QPoint> neighbours();

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
	double area() const;

	/** The Thermosphere at this Tile
	@return a reference to the thermosphere
	*/
	Thermosphere& thermosphere();
	/** The Troposphere at this Tile
	@return a reference to the troposphere
	*/
	Troposphere& troposphere();
	/** The Crust at this Tile
	@return a reference to the crust
	*/
	Crust& crust();
	/** The Mantle at this Tile
	@return a reference to the mantle
	*/
	Mantle& mantle();
	/** The OuterCore at this Tile
	@return a reference to the outer core
	*/
	OuterCore& outerCore();
	/** The InnerCore at this Tile
	@return a reference to the inner core
	*/
	InnerCore& innerCore();
	/** Causes erosion to adjacent tiles.*/
	void erode();



private:
	//static QPoint normalize( const QPoint& p ) const;
	int m_x, m_y;
	uint m_id;
	QPoint m_loc;
	QList<QPoint> m_neighbours;
	Simulation *m_parent;
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




