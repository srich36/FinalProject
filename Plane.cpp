//
// Created by sean on 4/16/18.
//

#include "Plane.h"
#include <iostream>

using namespace std;
Plane::Plane(int absoluteTime, int numcargo, int numpassengers, int numfamily, int numgrandchildren, int numfuel, string typeFlight){
    absoluteTimeAvailableForProcessing = absoluteTime;
    cargo = numcargo;
    passengers = numpassengers;
    family = numfamily;
    grandchildren = numgrandchildren;
    fuel = numfuel;
    typeOfFlight = typeFlight;
    priority = -1;
}


void Plane::refuel() {
    absoluteTimeAvailableForProcessing+=10;
    fuel+=30;
}

void Plane::update(int time, int timeSkipped = 1){

    if(timeSkipped > 1 && fuel > 0){
        fuel-=timeSkipped;
    }
    else if(fuel>0){
        fuel--;
    }

    if(fuel < 10){
     refuel();
    }

    if(time>=absoluteTimeAvailableForProcessing){
        requestAvailableForProcessing = true;
    }
    if(requestAvailableForProcessing) {
        waitTime = time - absoluteTimeAvailableForProcessing;
    }
    calculatePriority();
}

int Plane::calculateFuelFactor(int fuelAmount){
    int fuelFactor;
    if(fuelAmount != 0)
        fuelFactor = 20/fuelAmount;
    else
        fuelFactor = 1;
    return fuelFactor;
}

void Plane::calculatePriority() {

    if(!requestAvailableForProcessing)
        priority = -1;
    else {
        int fuelFactor = calculateFuelFactor(fuel);
        priority = family * FAMILY_FACTOR + grandchildren * GRANDCHILDREN_FACTOR + cargo * CARGO_FACTOR +
                   passengers * PASSENGER_FACTOR + fuelFactor * fuel;
        if(typeOfFlight == "D" || typeOfFlight == "d")
            priority+=DEPARTURE_FACTOR;
        else if(typeOfFlight == "A" || typeOfFlight == "a")
            priority+=ARRIVAL_FACTOR;
        else
            cout << "Error. Command not parsed correctly." << endl;
    }
}

void Plane::setCrash(bool planeCrashed){crashed = planeCrashed;}
int Plane::getcargo(){return cargo;}
int Plane::getpassengers(){return passengers;}
int Plane::getfamily(){return family;}
int Plane::getgrandchildren(){return grandchildren;}
int Plane::getwaitTime(){return waitTime;}
int Plane::getpriority(){return priority;}
int Plane::getcrashed(){return crashed;}
bool Plane::getrequestAvailableForProcessing(){return requestAvailableForProcessing;}
string Plane::getTypeOfFlight() {return typeOfFlight;}
int Plane::getabsoluteTimeAvailableForProcessing() {return absoluteTimeAvailableForProcessing;}

