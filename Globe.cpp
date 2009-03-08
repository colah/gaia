#include "Globe.h"

#include <QtCore/QList>

#include <cmath>


#include "GaiaGlobals.h"


Globe(int height, const Marble::PlanetaryConstants& planet, QObject *parent)
	: QObject(parent)
{
	m_size = QSize( 2*height, height );

	//Create the tiles.

	/*
	+--------------------------------------------------------------+
	|(-π, π/2)                                             (π, π/2)|
	|(0,0)                                    (m_size.width()-1, 0)|
	|                                                              |
	|                                                              |
	|                                                              |
	|                            (0,0)                             |
	|                                                              |
	|                                                              |
	|                                                              |
	|(-π, -π/2)                                           (π, -π/2)|
	|(0, m_size.height()-1)   (m_size.width()-1, m_size.height()-1)|
	+--------------------------------------------------------------+
	*/

	double inc = M_PI / static_cast<double>( m_size.height() );
	double lat = M_PI/2;
	double lon = -1.0 * M_PI;
	for( int x = 0; x < m_size.width(); ++x, lon += inc ) {
		double lat = M_PI/2;
		m_tiles.push_back( QList<Tile>() );
		for( int y = 0; y < m_size.height(); ++y, lat -= inc ) {
			GridCell cell;
			cell.top = lat;
			cell.bottom = lat - inc;
			cell.left = lon;
			cell.right = lon + inc;
			Tile *const t = new Tile(QPoint(x,y),cell,this);
			m_tiles[x].push_back(t);
		}
	}

}

const QSize& size() const;

Tile& at(int x, int y) const;

Tile& at(const QPoint& point) const;

/**
@return the planetary constants for this planet
*/
const Marble::PlanetaryConstants& planet() const;

private:
const Marble::PlanetaryConstants m_planet;

QList<QList<Tile> > m_tiles;

}
