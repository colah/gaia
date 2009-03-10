
#include "Planet.h"

int main(){
	Planet *planet = new Planet(10, 6e9);
	for (int j = 20; j >= -20; j--){
		cout << "π*" << j << "/20";
	}
	cout << endl;
	for (int i = 10; i >= -10; i--){
		cout << "π*" << i << "/20";
		for (int j = 20; j >= -20; j--){
			cout << " " << planet->getAtLL(M_PI*i/20,M_PI*j/20)->crust.base_height;
		}
		cout << endl;
	}
	cout << "Drop comet where?" << endl;
	cout << "Longitude:";	double lon; cin >> lon;
	cout << "Latitude: ";	double lat; cin >> lat;
	planet->commit(lat,lon);
	for (int j = 20; j >= -20; j--){
		cout << "π*" << j << "/20";
	}
	cout << endl;
	for (int i = 10; i >= -10; i--){
		cout << "π*" << i << "/20 ";
		for (int j = 20; j >= -20; j--){
			cout << " " << planet->getAtLL(M_PI*i/20,M_PI*j/20)->crust.base_height;
		}
		cout << endl;
	}

	return 0;

}