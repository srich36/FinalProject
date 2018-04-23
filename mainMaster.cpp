//
// Created by sean on 4/16/18.
//
/*
 *
 *
 *
 *
 *
 * MAIN MASTER IS THE MAIN .CPP FILE WE WILL BE USING TO RUN OUR PROGRAM FROM
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include "Plane.h"
#include "Input.h"
//#include "ATCclass.h"
#include "PlaneStats.h"
#include "Queue.h"
using namespace std;

int main(){

    //ATC controller;
    Input object;

    //THIS WILL PASS CONTROLLER INTO  THE parseAndCreateQueue METHOD WHEN THE ATC CLASS IS FULLY IMPLEMENTED//

    object.parseAndCreateQueue();//controller);
    //controller.process();
    return 0;
}