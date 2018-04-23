//
// Created by sean on 4/16/18.
//

#include <iostream>
#include "Plane.h"
#include "Input.h"
//#include "ATCclass.h"
//#include "Stats.h"
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define DATASIZEMAX 8


using namespace std;

int main(){

   // ATC controller;

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
    Plane plane1 = Plane(object.getTime(), static_cast<int>(object.getCargo()), object.getPeople(), object.getFamily(), object.getGrand(), object.getFuel(), object.getCommand());
   // controller.buildQueue(plane1);
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