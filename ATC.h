//
// Created by sean on 4/23/18.
//

#ifndef FINALPROJECT_ATC_H
#define FINALPROJECT_ATC_H

#include "Plane.h"
#include "Queue.h"
#include "PlaneStats.h"
#include <iostream>
using namespace std;

/*
* The ATC class takes the following arguments in its constructor: none. The constructor initializes the data structure.
*
* Methods:
*
* Public:
*
* Getter method:
* The ATC class will have getter methods for all the attributes named getAttributeName where AttributeName is the name
* of the variable that is returned from the method.
*
* Additional Methods:
*
*	process(): This method will be called on a loop by the main method once the
*				entire input file has been parsed and built into a queue. It will continue to be called as
*				long as there are still objects in the queue. This method first calls sort() to sort the available actions
*				in the queue by priority, then calls act() once, checks if another action is available with actionAvailable() (and acts again if necessary),
*				and then updates the absolute time with updateTime().
*
*	act(): This method is called by the process() method. First, it will pass
*			the plane object, along with the absolute time of the action to the statistics class using updateStatistics(plane, absoluteTime). Finally, the
*			the method will dequeue the plane using the delFront() method of the linked list data structure class.
*
*	updateTime(): This method is called at the end of each processing (process()) call, after at least one action has completed, two if possible.
*					It calls the actionAvailable() method, and if that returns true, time is only incremented by one unit, because more actions need
*					to be taken in the next available opportunity, which is the next time unit. If actions are not available, the method accesses the
*					first element of the data structure, looks at its time attribute (for when it can be acted on) and sets the current absolute time
*					to that value.
*
*	actionAvailable(): This method accesses the first element in the queue using THIS METHOD. If the availablility of the first item of the queue is not -1
*						(it is available) then this method will return true. It will return false otherwise.
*
*	crash(): This method informs the plane class the the plane has crashed using plane.setCrash(boolean). ??? Does ATC then pass this plane to state, or does plane?
*
*	buildQueue(): This method is called by the input class each time it parses a new line of the input that is a plane. It will add each of those
*					objects to the back of the queue using the addBack() method of the linked list class.
*
* Private:
*
*
*
*
*/


class ATC {
private:
	int absoluteTime;
    Queue PlaneRequests;
    PlaneStats Stats;

public:
	ATC();
	void act();
	void updateTime();
	bool actionAvailable();
	void crash(Plane *);
	void buildQueue(Plane *);
	void process();
    void printQueue(bool DEBUG);
    void printStats();
    void processAllRequests();
    int getAbsoluteTime();
	};




//#include "ATCclass.h"
using namespace std;

ATC::ATC() {
    absoluteTime = 0;

}

void ATC::process() {
    PlaneRequests.sort();
    if (actionAvailable())
        act();
    if (actionAvailable())
        act();
    updateTime();

}

void ATC::act() {
    Stats.updateAll(absoluteTime, *(PlaneRequests.getFirst()->plane1));
    PlaneRequests.removeFront();
}

void ATC::updateTime() {
    if (PlaneRequests.getFirst() == nullptr) {
        absoluteTime += 0;
    }
    else {
    int timeskip = 1;
    if (actionAvailable())
        absoluteTime += 1;
    else {
        timeskip = PlaneRequests.getFirst()->plane1->getabsoluteTimeAvailableForProcessing() - absoluteTime;
        absoluteTime += timeskip;
    }
    node *temp = PlaneRequests.getFirst();
    while (temp != 0) {
        bool crashed = false;
        temp->plane1->update(absoluteTime, timeskip, crashed); //this second value is just one because default params have not been implemented
        if(crashed){
            temp->plane1->setCrash(crashed);
            node *temp2 = temp;
            temp = temp->next;
            Stats.updateAll(absoluteTime, *(temp2->plane1));
            PlaneRequests.deleteElement(temp2->plane1);

        }
        if(!crashed) //because when crashed you already increment it
            temp = temp->next;
    }
}
    //else
    //	absoluteTime = queue[0]->time;
}

bool ATC::actionAvailable() {
    if ((PlaneRequests.getFirst()==nullptr))
        return false;
    else if ((PlaneRequests.getFirst()->plane1->getpriority()) != -1)
        return true;
    return false;
}

void ATC::crash(Plane *planeCrashed) {
    planeCrashed->setCrash(true);
}

void ATC::buildQueue(Plane *plane1) {
    PlaneRequests.addElementBack(plane1);
}

void ATC::printQueue(bool DEBUG = false){
    PlaneRequests.print(DEBUG);
}

void ATC::printStats(){
    Stats.print();
}

void ATC::processAllRequests(){
    while(PlaneRequests.size()!=0){
        process();
    }
}

int ATC::getAbsoluteTime(){return absoluteTime;}
#endif //FINALPROJECT_ATC_H
