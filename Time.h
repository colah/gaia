
#ifndef STIME_H
#define STIME_H

#include "Simulation.h"

/**The Simulation's time handling.*/
class Time 
{
public:

	/**Increment the Simulation's time by an hour.*/
	void operator++ ();

private:

	/**Do whatever the simulation needs to have done as time increases..*/
	void runSchedule();
	/**The Simulation's time in hours..*/
	unsigned int hour;
	Simulation *planet;

}
#endif