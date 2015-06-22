/*
* MyBike.h
*/
#ifndef __MYBIKE_H__
#define __MYBIKE_H__

#include <iostream>

class MyBike {
	
public: 
	
	MyBike();
	
	MyBike(const char* p, int y);
	
	~MyBike();
	
	MyBike(const MyBike& s);
	
	MyBike& operator=(const MyBike& s);
	
	void repair();
	
	void display();

	int getPrice();
	
private:
	char *brand;
	int price;
};

#endif
