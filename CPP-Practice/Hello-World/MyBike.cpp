#include "MyBike.h"

MyBike::MyBike() {
	brand = new char[1];
brand[0] = '\0';

	price = -1;
}

MyBike::MyBike(const char *p,int y) {
	if(p) {
		int len = strlen(p);
		brand = new char[len];
		strcpy(brand,p);
	} else {
		brand = new char[1];
		brand[0] = '\0';
	}
	price = y;
}

MyBike::MyBike(const MyBike& b) {
	price = b.price ;
	//	price = 9;
	int len = strlen(b.brand);
	brand = new char[len];
	strcpy(brand,b.brand);
	/*
	   brand = new char[3];
	   brand[0] = 'a';
	   brand[1] = 'b';
	   brand[2] = 'c'; */
}

MyBike& MyBike::operator=(const MyBike& rhs) {

	if(this == &rhs) {
		return *this;
	} 

	price = rhs.price;

	delete[] brand;
	int len = strlen(rhs.brand);
	brand = new char[len];
	strcpy(brand,rhs.brand);

	return *this;
}

MyBike::~MyBike() {
	delete[] brand;
}

void MyBike::repair() {
	price = price + 100;
}

void MyBike::display() {
	printf("%s\n", brand);
	printf("%d\n",price);
}

int MyBike::getPrice() {
	return price;
}
