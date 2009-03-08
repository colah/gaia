#include "Tile.h"

#include <cmath>
using std::sin;

Tile(const QPoint& pos, const GridCell& cell, Globe* globe)
	: QObject(globe)
{
	m_globe = globe;
	m_gridCell = cell;
	/*
	The formula for area is:
	\frac{ 4 \pi^2 r^2 \lvert \sin \theta_1 - \sin \theta_2 \rvert }
	{\lvert \lambda_2 - \lambda_1 \rvert}
	*/
	//nurrr, need to add Planet class to Marble first....
	double r = m_globe
	m_area =
	( 4.0 * M_PI * M_PI * 
	
}

const GridCell& gridCell() const;

///In km²
double area() const;

Globe *const globe() const;

void paint( Marble::GeoPainter *const p ) const;


/*
private:
	Globe *const m_globe;
	GridCell m_gridCell;
	QPoint m_pos;
	double m_area;

/*

Note: Add other data (lists of organisms etc) here.



}
*/