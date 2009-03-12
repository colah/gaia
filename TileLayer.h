
#ifndef TILELAYER_H
#define TILELAYER_H

class Tile;

/**A class that is inherited by all container classes that go in a tile.*/
class TileLayer
{
public:
	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	TileLayer();
	/** Constructor—Invalid
	Creates an invalid object. Don't try to use an object created this way.
	*/
	TileLayer( Tile* parent );
	/** Get this tile layer's parent tile.
	@return this tile's parent
	*/
	Tile* tile();
private:
	Tile* m_parent;
};

#endif


