
#include "Simulation.h"
#include <iostream>
#include <cmath>

using namespace std;
using namespace Marble;

int main(){
	//TODO: use the planet factory
	Planet p( 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6372000 );
	Simulation *planet = new Simulation(10, p);
	for (int j = 20; j >= -20; j--){
		cout << "π*" << j << "/20";
	}
	cout << endl;
	for (int i = 10; i >= -10; i--){
		cout << "π*" << i << "/20";
		for (int j = 20; j >= -20; j--){
			cout << " " << planet->getAtLL(M_PI*j/20,M_PI*i/20)->crust().baseHeight();
		}
		cout << endl;
	}
	cout << "Drop comet where?" << endl;
	cout << "Longitude:";	double lon; cin >> lon;
	cout << "Latitude: ";	double lat; cin >> lat;
	planet->comet(lat,lon);
	for (int j = 20; j >= -20; j--){
		cout << "π*" << j << "/20";
	}
	cout << endl;
	for (int i = 10; i >= -10; i--){
		cout << "π*" << i << "/20 ";
		for (int j = 20; j >= -20; j--){
			cout << " " << planet->getAtLL(M_PI*j/20,M_PI*i/20)->crust().baseHeight();
		}
		cout << endl;
	}

	return 0;

}

