#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {


	ifstream stream(argv[1]);
	string line;
	int firstrun = 1;

	while(getline(stream,line)) {
		if(firstrun == 0) {
			cout << endl;
		}
		firstrun = 0;
		int stringLength = line.size();
		for(int i = 0; i < stringLength; i++) {
			char tempChar = line[i];
			bool unique = true;
			for(int a = 0; a < stringLength;a++) {
				if(a!=i){
					if(tempChar == line[a]){
						unique = false;
					}
				}	
			}
			if(unique == true) {
				cout << tempChar;		
				i = stringLength;
			}
		}

	}	
	return 0;
}
