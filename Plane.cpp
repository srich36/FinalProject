//
// Created by sean on 4/16/18.
//

#include "Plane.h"
using namespace std;
Plane::Plane(int absoluteTime, int numcargo, int numpassengers, int numchildren, int numgrandchildren){
    absoluteTimeAvailableForProcessing = absoluteTime;
    cargo = numcargo;
    passengers = numpassengers;
    children = numchildren;
    grandchildren = numgrandchildren;
}


void Plane::update(int time){
    return;
}

void Plane::setCrash(bool planeCrashed){crashed = planeCrashed;}
int Plane::getcargo(){return cargo;}
int Plane::getpassengers(){return passengers;}
int Plane::getchildren(){return children;}
int Plane::getgrandchildren(){return grandchildren;}
int Plane::getwaitTime(){return waitTime;}
int Plane::getpriority(){return priority;}
int Plane::getcrashed(){return crashed;}
bool Plane::getrequestAvailableForProcessing(){return requestAvalaiableForProcessing;}