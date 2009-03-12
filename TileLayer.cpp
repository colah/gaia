
#include "TileLayer.h"

TileLayer::TileLayer()
{
}

TileLayer::TileLayer( Tile* parent )
	: m_parent( parent )
{
}

Tile* TileLayer::tile()
{
	return m_parent;
}
