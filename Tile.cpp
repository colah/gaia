

//Classes and breif descritions. Doxygen descritions are later.
class Planet;

class Tile;
class sub_tile;    /*A class that is inherited by all container classes that go in a tile.*/
class Thermosphere;/*The thermosphere is the main part of the atmosphere of a planet.*/
class Troposphere; /*The Troposphere is the atmosphere of a planet from the crust
                    *to a height that is chemcially identical due to convection.*/
class Crust;       /*The Crust is the outermost solid layer of a planet.*/
class Mantle;      /*The Mantle is the main solid part of a planet.*/
class Outer_Core;  /*The Outer Core is the hot liquid near-center of a planet.*/
class Inner_Core;  /*The Inner Core is the hot, very dense center of a planet.*/

/**A class that is inherited by all container classes that go in a tile.*/
class sub_tile{

};

/**The thermosphere is the main part of the atmosphere of a planet.*/
class Thermosphere: sub_tile{

};
/**The Troposphere is the atmosphere of a planet from the crust
  *to a height that is chemcially identical due to convection.*/
class Troposphere: sub_tile{
};
/**The Crust is the outermost solid layer of a planet.*/
class Crust: sub_tile{
	public:
	double area; 	   /**< Area in m^2*/
	double firmness;   /**< Resistance to erosion.*/
	double roughness;  /**< Roughness of turain: hills, valies*/
	double base_height;/**< Height in m from radius.*/
};
/** The Mantle is the main solid part of a planet.*/
class Mantle: sub_tile{

};
/** The Outer Core is the hot liquid near-center of a planet.*/
class Outer_Core: sub_tile{

};
/** The Inner Core is the hot, very dense center of a planet.*/
class Inner_Core: sub_tile{

};


/**
 * An object of Tile represents a certain amount of space on the gloce. This space
 * goes from the edge of the atmosphere to the inner core. Not all objects of Tile
 * occupy the same area (it depends on longitude and latitude). Thus, where possible
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
 *|             |  Outer_Core:  Hot; Liquid; molten.
 *|             |_ Inner_Core:  Hot; solid and dense due to pressure.
 *|___________________________________________________________________________</pre>
 * 
 * @note: The names of planetary layers are capetalized so that we can have their 
 * lower case in Tiles. This concept is actually aplied in other cases, as well.   */
class Tile{

	
	public:
int id;
	/*General Things */

	Planet *planet; ///<The Planet that this is a Tile of.

	Tile   *north, ///< Tile to North (that is, towards upper pole).
	       *south, ///< Tile to South.
	       *east, ///< Tile to East.
	       *west; ///< Tile to West.

	double longitude, ///< The longitude of this tile. @note In formulas, longitude is \f$ \lambda \f$
	       latitude; ///< The latitude of this tile. @note In formulas, latitude is \f$ \phi \f$


	double area; /**< The area at average planetary radius in m^ \f$^2 \f$, everything else should
	                * be in terms of density (eg. moles/m \f$^2 \f$)                      */

/* 
 *
 * --- Planetary Layers (that we implement) ---
 * ___________________________________________________________________________
 *\   PART      \   NAME    \  DESCRIPTION                                    \
 *\_____________\___________\_________________________________________________\
 *\              _
 *\ Atmosphere: \Thermosphere: Different chemical composition due to gass mass.
 *\             \              GHGs and ozone. Main atmospheric component.
 *\             \Troposphere:  From crust to reasonable hight. It is chemicaly
 *\             \_             consistant due to convection.
 *\              _
 *\             \ Crust:       Surface.
 *\ Solid:      \ Mantle:      Majority of solid planet.
 *\             \ Outer Core:  Hot; Liquid; molten.
 *\             \_Inner Core:  Hot; solid and dense due to pressure.
 *\___________________________________________________________________________
 * 
 * NOTE: The names of planetary layers are capetalized so that we can have their 
 * lower case in Tiles. This concept is actually aplied in other cases, as well.
 */

	Thermosphere thermosphere; ///< The Thermosphere at this Tille
	Troposphere  troposphere;  ///< The Troposphere at this Tile
	Crust        crust;        ///< The Crust at this Tile
	Mantle       mantle;       ///< The Mantle at this Tile
	Outer_Core   outer_core;   ///< The Outer_Core at this Tile
	Inner_Core   inner_core;   ///< The Inner_Core at this Tile
	

};



