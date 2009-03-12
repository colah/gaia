#include "Time.h"

void Time::operator++ (){
	hour++;
	runSchedule();
}

void Time::runSchedule(){
	if (hour % 5 == 0){
		planet->erode();
	}
	if (hour == 1000){
		hour = 0;
	}
}
