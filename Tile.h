
#ifndef TILE_H
#define TILE_H

#include <QtCore/QObject>

#include <marble/PlanetaryConstants.h>

#include "GaiaGlobals.h"

namespace Marble {
	class GeoPainter;
}

typedef struct {
	///In radians
	double top, bottom, left, right;
} GridCell;

class Tile : public QObject
{
	Q_OBJECT
public:
	Tile(const QPoint& pos, const GridCell& cell, Globe* globe);

	const GridCell& gridCell() const;

	///In km²
	double area() const;

	Globe* globe() const;

public slots:
	void paint( Marble::GeoPainter* p ) const;
private:
	Globe* m_globe;
	GridCell m_gridCell;
	QPoint m_pos;
	double m_area;

/*

Note: Add other data (lists of organisms etc) here.

*/

}

#endif

