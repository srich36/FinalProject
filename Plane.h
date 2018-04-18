//
// Created by sean on 4/16/18.
//

#ifndef FINALPROJECT_PLANE_H
#define FINALPROJECT_PLANE_H

#include <iostream>
using namespace std;

/*
 * The plane class takes the following arguments in its constructor: absolute time of the request (i.e. absolute time
 * when the request is able to be processed, number of cargo,
 * number of passengers, number of children, number of grandchildren, in this order
 *
 * Methods:
 *
 * Public:
 *
 * Getter method:
 * The Plane class will have getter methods for all the attributes named getAttributeName where AttributeName is the name
 * of the variable that is returned from the method.
 *
 * Additional Methods:
 *
 * update(absoluteTime): Update takes one parameter: the absolute time of the update. This should be called on every plane object once
 * a time unit passes. The update method will provide the following functionality: it will decrement fuel by 1, update wait
 * time (because the priority score depends on wait time), recalculate priority, and will determine and set the boolean variable
 * of request available for processing variable. This variable is used for easy interfacing with the ATC class so you can just call
 * getrequestAvailableForProcessing to easily determine which planes (aka requests) are available to land or depart at the
 * given time unit. Note: the priority of planes with requests not available for processing will be set = to -1.
 *
 * setCrash: setCrash will take a boolean parameter and will set the crashed variable of the plane to whatever is passed in.
 * This method should be called by the ATC class when it is determined that a plane must be crashed. Once called, this will
 * change the crashed variable so it can the be passed into the update method of the statistics class.
 *
 * Private:
 *
 * calculatePriority(): This is a private helper function that implements the formula for calculating priority. This is hidden from
 * other class access because only the plans should be able to set the priority of itself.
 */

class Plane {

private:
    int cargo;
    int passengers;
    int children;
    int grandchildren;
    int absoluteTimeAvailableForProcessing;
    int waitTime;
    int priority;
    bool crashed;
    bool requestAvalaiableForProcessing;

    void calculatePriority();

public:
    Plane(int absoluteTime, int cargo, int passengers, int children, int grandchildren);
    void update(int time);
    void setCrash(bool planeCrashed);
    int getcargo();
    int getpassengers();
    int getchildren();
    int getgrandchildren();
    int getwaitTime();
    int getpriority();
    int getcrashed();
    bool getrequestAvailableForProcessing();
};


#endif //FINALPROJECT_PLANE_H
