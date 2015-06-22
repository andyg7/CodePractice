#include <iostream>
using namespace std;

class Rectangle {

	int width;
	int height;

	public:
	Rectangle();
	Rectangle(int,int);
	void set_values(int,int);
	int area() {return width*height;}
};

void Rectangle::set_values(int x, int y) {
	width = x;
	height = y;
}

Rectangle::Rectangle() {

}

Rectangle::Rectangle(int a, int b) {
	width = a;
	height = b;
}

int main() {

	Rectangle rect;
	Rectangle rectb(5,6);
	rect.set_values(3,4);
	cout << "area of a: " << rect.area() << endl;
	cout << "area of b: " << rectb.area() << endl;
	return 0;
}

