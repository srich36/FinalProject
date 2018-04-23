// ATCclass.cpp : Defines the entry point for the console application.
//

#ifndef FINALPROJECT_ATC_H
#define FINALPROJECT_ATC_H
#include "Plane.h

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

public:
	ATC();
	void act();
	void updateTime();
	bool actionAvailable();
	void crash();
	void buildQueue();
	void process();
	};

#endif //FINALPROJECT_ATC_H

//#include "ATCclass.h"
using namespace std;

ATC::ATC() {

}

void ATC::process() {
	sort();
	act();
	if (actionAvailable())
		act();
	updateTime();
	
}

void ATC::act() {
	statistics(queue[0]);
	delFront();
}

void ATC::updateTime() {
	if (actionAvailable())
		absoluteTime += 1;
	else 
		absoluteTime = queue[0]->time;
}

bool ATC::actionAvailable() {
	if (queue[0]->available != -1)
		return true;
	return false;
}

void ATC::crash(plane planeCrashed) {
	planeCrashed.setCrash(true);
	//statistics(plane); is this handled here or in plane?
}

void ATC::buildQueue(Plane plane1) {
	addBack(plane1);
}