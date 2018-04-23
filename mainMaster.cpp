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
    Input object;
    object.parseAndCreateQueue();
   // controller.process();

    //Prompting the user for the filename.

    system("pause");
    return 0;
}