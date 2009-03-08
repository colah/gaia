#ifndef GLOBE_H
#define GLOBE_H

#include <QtCore/QObject>

#include <marble/PlanetaryConstants.h>

#include "GaiaGlobals.h"

/**
@class Globe A container class that holds the data of a global simulation
*/
class Globe : public QObject
{
	Q_OBJECT
public:
	/**
	@param height the number of tiles on the y axis. 2*height = width
	*/
	Globe(int height, const Marble::PlanetaryConstants& planet);
	/**
	@return the size of the planetary grid
	*/
	const QSize& size() const;

	/**
	@return a pointer to the tile at the location @p x, @p y.
	@note if X and Y are bigger than the size of the grid, it will wrap around.
	*/
	Tile *const at(int x, int y) const;

	/**
	@return a pointer to the tile at the location @p point.
	@note if X and Y are bigger than the size of the grid, it will wrap around.
	*/
	Tile *const at(const QPoint& point) const;

	/**
	@return the planetary constants for this planet
	*/
	const Marble::PlanetaryConstants& planet() const;

private:
	const Marble::PlanetaryConstants m_planet;
	QSize m_size;

	QList<QList<Tile *const> > m_tiles;

}

#endif
