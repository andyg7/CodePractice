#include <iostream>
#include "MyBike.h"

int main() {
	
	MyBike Sbike("Specialized", 1000);
	MyBike Tbike("Trek", 700);
	
	Sbike.repair();
	
	MyBike Gbike = Sbike;
	Gbike = Tbike;
	Gbike.display();
	
	printf("%d\n", Gbike.getPrice());

	return 0;
}
