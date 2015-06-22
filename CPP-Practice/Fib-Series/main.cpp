#include <iostream>
#include <fstream>
using namespace std;
int calcFib(int x);
int main(int argc, char *argv[]) {

	ifstream stream(argv[1]);
	string line;
	int firstRun = 1;
	while(getline(stream,line)) {
		if(firstRun == 0) {
			cout << endl;
		}
		firstRun = 0;
		int i = stoi(line);
		cout  <<  calcFib(i); 
	}

	return 0;

}

int calcFib(int x) {

	int a = 0;
	int b = 1;
	int sum = a + b;
	if(x == 0) {
		return 0;
	}
	if(x == 1) {
		return 1;
	}
	for(int i = 0; i < x-1 ; i++) {
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}
