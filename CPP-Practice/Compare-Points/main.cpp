#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {

	ifstream stream(argv[1]);
	string  line;
	int firstrun = 1;

	while(getline(stream,line)) {
		if(firstrun == 0) {
			cout << endl;
		}
		firstrun = 0;

		vector<int> v;
		int x1,y1,x2,y2;
		int counter = 0;
		int stringLen = line.size();
		string tempS = "";
		for(int i = 0;i < stringLen;i++) {
			if(line[i] != ' '){
				if(i == stringLen - 1){
					tempS += line[i];
					//cout << tempS << endl;
					int num = atoi(tempS.c_str());
					switch(counter) {
						case 0:
							x1 = num;
							counter++;
							break;
						case 1:
							y1 = num;
							counter++;
							break;
						case 2:
							x2 = num;
							counter++;
							break;
						case 3:
							y2 = num;
							counter++;
							break;

					}
				} else{
					tempS+=line[i];

				}
			} else {
				//	cout << tempS << endl;
				int num = atoi(tempS.c_str());
				switch(counter) {
					case 0:
						x1 = num;
						counter++;
						break;
					case 1:
						y1 = num;
						counter++;
						break;
					case 2:
						x2 = num;
						counter++;
						break;
					case 3:
						y2 = num;
						counter++;
						break;

				}
				tempS = "";

			}
		}
		int xdiff; 
		if((x2-x1)==0) {
			xdiff = 0;
		} else{
			xdiff = (x2 - x1)/abs(x2 - x1);
		}
		int ydiff;
		if((y2-y1)==0){
			ydiff = 0;
		} else {
			ydiff = (y2 - y1)/abs(y2 - y1);
		}	
		string direction = "";
		switch(ydiff) {
			case 0:
				break;
			case 1:
				direction += "N";
				break;
			case -1:
				direction += "S";
				break;
		}
		switch(xdiff) {
			case 0:
				break;
			case 1:
				direction += "E";
				break;
			case -1:
				direction += "W";
				break;
		}
		if(direction == "") {
			direction = "here";
		}
		cout << direction;
	}
	return 0;
}
