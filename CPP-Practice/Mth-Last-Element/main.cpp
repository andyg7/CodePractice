#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {

	ifstream stream(argv[1]);
	string line;
	int firstRun = 1;
	while(getline(stream,line)) {
		if(firstRun == 0) {
			cout << endl;
		}
		firstRun = 0;
		int stringLength = line.size();
		if(line[stringLength-1 == ' ']){
			int mth = int(line[stringLength - 1]) - '0';
			cout << line[stringLength - (2 * mth) - 1];

		} else {
			cout << "a";
		}
	}
	return 0;
}
