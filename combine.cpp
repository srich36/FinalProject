﻿
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define DATASIZEMAX 8
#include "Plane.h"

using namespace std;

class input {
private:
	string command, action;
	int time, fuel, people, family, grand;
	double cargo;
public:
	//Process function takes string lineinput as parameter. Returns nothing.
	//Takes lineinput string and parses it.
	void process(string lineinput) {
		string arry[DATASIZEMAX];
		int count = 0;
		for (int i = 0; i < DATASIZEMAX; i++) {
			arry[i] = "";
		}
		string parse = "";

		//Goes through line and if character is a letter, number, or period, add to parse string.
		//When character is not a letter, number, or period, ie. a comma, put parse string into array. Set parse string to empty.
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
		//Command will always be the first element of the array.
		command = arry[0];
		//If data command, set variables equal to rest of elements in array.
		if (command == "D") {
			time = stoi(arry[1]);
			action = arry[2];
			fuel = stoi(arry[3]);
			people = stoi(arry[4]);
			cargo = stoi(arry[5]);
			family = stoi(arry[6]);
			grand = stoi(arry[7]);
		}
		//If the command is W or P, we null the rest of the values.
		else {
			time = NULL;
			action = "";
			fuel = NULL;
			people = NULL;
			cargo = NULL;
			family = NULL;
			grand = NULL;
		}

	}

	//Below are get functions. Use object.get*** in main class to call these values.
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

//Plane

Plane::Plane(int absoluteTime, int numcargo, int numpassengers, int numchildren, int numgrandchildren, int numfuel) {
	absoluteTimeAvailableForProcessing = absoluteTime;
	cargo = numcargo;
	passengers = numpassengers;
	children = numchildren;
	grandchildren = numgrandchildren;
	fuel = numfuel;
}

void Plane::refuel() {
	absoluteTimeAvailableForProcessing += 10;
	fuel += 30;
}

void Plane::update(int time) {

	if (fuel>0) {
		fuel--;
	}
	if (time == absoluteTimeAvailableForProcessing) {
		requestAvailableForProcessing = true;
	}
	if (requestAvailableForProcessing) {
		waitTime = time - absoluteTimeAvailableForProcessing;
	}
	calculatePriority();
}

double Plane::calculateFuelFactor(int fuelAmount) {
	double fuelFactor = 20 / fuelAmount;
	return fuelFactor;
}

void Plane::calculatePriority() {

	if (!requestAvailableForProcessing)
		priority = -1;
	else {
		double fuelFactor = calculateFuelFactor(fuel);
		priority = children * CHILDREN_FACTOR + grandchildren * GRANDCHILDREN_FACTOR + cargo * CARGO_FACTOR +
			passengers * PASSENGER_FACTOR + fuelFactor * fuel;
	}
}

void Plane::setCrash(bool planeCrashed) { crashed = planeCrashed; }
int Plane::getcargo() { return cargo; }
int Plane::getpassengers() { return passengers; }
int Plane::getchildren() { return children; }
int Plane::getgrandchildren() { return grandchildren; }
int Plane::getwaitTime() { return waitTime; }
int Plane::getpriority() { return priority; }
int Plane::getcrashed() { return crashed; }
bool Plane::getrequestAvailableForProcessing() { return requestAvailableForProcessing; }
char Plane::getTypeOfFlight() { return typeOfFlight; }


int main() {
	//Prompting the user for the filename.
	string filename;
	cout << "What is the name of the file?" << endl;
	cin >> filename;
	//Creating an object that can access the functions in the input class.
	input object;
	//fstream does not accept string as parameters so we need to convert to constant char* using .c_str()
	fstream myFile(filename.c_str());
	string lineinput;
	//Reads until file is complete, ie no more newlines.
	while (myFile.good()) {
		//First line of myFile is set as the string lineinput.
		getline(myFile, lineinput);
		//Ignores the instances where lines are completely blank.
		if (lineinput != "") {
			//Calls process functions in input class which splits by commas.
			//You can get the value by calling object.get*****().
			object.process(lineinput);
			//If it is data, we create a new plane object by passing the values found in input into the plane constructor.
			//We now have an plane object called plane1 which can call the functions in plane class using this data.
			if (object.getCommand() == "D") {
				Plane plane1 = Plane(object.getTime(), static_cast<int>(object.getCargo()), object.getPeople(), object.getFamily(), object.getGrand(), object.getFuel());
				//cout << plane1.getchildren() << endl;








			}
		}
		else {
			;//pass
		}
	}
	myFile.close();
	system("pause");
	return 0;
}

