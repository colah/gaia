

void operator++ (){
	hour++;
	runSchedule();
}

void runSchedule(){
	if (hour % 5 == 0){
		planet->erode();
	}
	if (hour == 1000){
		hour = 0;
	}
}