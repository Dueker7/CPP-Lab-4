#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void drawBarGraph(vector<float> tempInput) {
	ofstream outFile;
	outFile.open("TempOutput.dat");
	//creating the bar graph
	float temp;
	cout << "-30         0                                        120" << endl;
	outFile << "-30         0                                        120" << endl;
	for (int i = 0; i < tempInput.size(); i++) {

		//checking if any inputs are out of range
		if (tempInput[i] <= 120 && tempInput[i] >= -30) {
			//checks if number is negative
			if (tempInput[i] < 0) {
				temp = tempInput[i] / 3;
				if (temp < 0 && temp > -1) { temp = 0; }
				switch (static_cast<int>(temp)) {
				case 0:
					cout << " |          |";
					outFile << " |          |";
					break;
				case -1:
					cout << " |         *|";
					outFile << " |         *|";
					break;
				case -2:
					cout << " |        **|";
					outFile << " |        **|";
					break;
				case -3:
					cout << " |       ***|";
					outFile << " |       ***|";
					break;
				case -4:
					cout << " |      ****|";
					outFile << " |      ****|";
					break;
				case -5:
					cout << " |     *****|";
					outFile << " |     *****|";
					break;
				case -6:
					cout << " |    ******|";
					outFile << " |    ******|";
					break;
				case -7:
					cout << " |   *******|";
					outFile << " |   *******|";
					break;
				case -8:
					cout << " |  ********|";
					outFile << " |  ********|";
					break;
				case -9:
					cout << " | *********|";
					outFile << " | *********|";
					break;
				case -10:
					cout << " |**********|";
					outFile << " |**********|";
					break;
				}
				cout << endl;
				outFile << endl;
			}
			else {
				//dividing inputs by 3 to make each * count as 3 degrees
				temp = tempInput[i] / 3;

				//finding the amount of *s to draw and drawing them
				cout << " |          |";
				outFile << " |          |";
				for (int a = 0; a < temp; a++) {
					cout << "*";
					outFile << "*";
				}
				
				cout << endl;
				outFile << endl;
			}
		}
		else {
			//exits the program due to out of range inputs
			cout << "ERROR: Tempature out of range! Acceptable range is -30 through 120." << endl;
			exit(EXIT_FAILURE);
		}
	}
}

int main()
{
	//open files
	ifstream inFile;
	inFile.open("TempInput.dat");

	//get data from input files and convert the strings to floats
	string rawTempInput;
	vector<float> tempInput;

	while (getline(inFile, rawTempInput)) {
		tempInput.push_back(stof(rawTempInput));
	}

	//call the draw graph function
	drawBarGraph(tempInput);
}