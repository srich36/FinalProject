//
// Created by sean on 4/23/18.
//

#ifndef FINALPROJECT_INPUT_H
#define FINALPROJECT_INPUT_H


#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define DATASIZEMAX 8
#include "Plane.h"
#include <cctype>
#include "ATC.h"

using namespace std;

class Input {
private:
	string command, action;
	int time, fuel, people, family, grand, absolutetime;
	double cargo;
public:
	Input() {
		absolutetime = 1;
	}
	void process(string lineinput) {
		string arry[DATASIZEMAX];
		int count = 0;
		for (int i = 0; i < DATASIZEMAX; i++) {
			arry[i] = "";
		}
		string parse = "";
		for (int i = 0; i < lineinput.size(); i++) {
			if (isalpha(lineinput[i]) || isdigit(lineinput[i]) || lineinput[i] == '.') {
				parse += lineinput[i];
				int j = i + 1;
				while (isalpha(lineinput[j]) || isdigit(lineinput[j]) || lineinput[j] == '.') {
					parse += lineinput[j];
					j++;
				}
				i = j;
				arry[count] = parse;
				count++;
				parse = "";
			}
		}
		
		command = arry[0];
		if (command == "d" || command == "D") {
			absolutetime += stoi(arry[1]);
			time = absolutetime;
			action = arry[2];
			fuel = stoi(arry[3]);
			people = stoi(arry[4]);
			cargo = stoi(arry[5]);
			family = stoi(arry[6]);
			grand = stoi(arry[7]);
		}
		
		else{

			time = -1;
			action = -1;
			fuel = -1;
			people = -1;
			cargo = -1;
			family = -1;
			grand = -1;
		}

	}
	void parseAndCreateQueue(ATC &controller) {
		string filename;
		cout << "What is the name of the file?" << endl;
		cin >> filename;
		fstream myFile(filename.c_str());
        //cout << myFile.is_open() << endl; //tests to see if the file is opened
		string lineinput;
		cout << "Filename is: " << filename.c_str() << endl;
		while (myFile.good()) {
			getline(myFile, lineinput);
			if (lineinput != "") {
				process(lineinput);
				
				if (getCommand() == "D" || getCommand() == "d") {
					Plane *planeObject = new Plane(getTime(), static_cast<int>(getCargo()), getPeople(), getFamily(), getGrand(), getFuel(), getAction());
					//cout << planeObject->getpassengers() << endl; //Test to see that it works.
					controller.buildQueue(planeObject);
					//controller.printQueue(true);

				}
                else if(command == "P" || command == "p"){
                    controller.processAllRequests();
                    controller.printStats();
                }
                else if(command == "w" || command == "W"){
                    string temp;
                    cout << "Wating for carriage return. Hit enter when ready to continue " << endl;
                    cin.ignore();
                    getline(cin, temp);
                }
			}
			else {
				;
			}
		}
		myFile.close();
	}
	string getCommand() {
		return command;
	}
	int getTime() {
		return time;
	}
	string getAction() {
		return action;
	}
	int getFuel() {
		return fuel;
	}
	int getPeople() {
		return people;
	}
	double getCargo() {
		return cargo;
	}
	int getFamily() {
		return family;
	}
	int getGrand() {
		return grand;
	}

	

};



#endif //FINALPROJECT_INPUT_H
