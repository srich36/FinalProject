#ifndef FINALPROJECT_STATS_H    // since .h file
#define FINALPROJECT_STATS_H    // defines file

//#include "stdafx.h"           // needed for VS
#include "Plane.h"              // to use Sean's plane class
#include <time>                 // to get runtime (needed for print function) ACTUALLY USE

#include <iostream>
using namespace std;

///////////////////////////////////////
// CLASS -- DEFINITION
///////////////////////////////////////
class Stats
{
private:
    //
    // variables to be printed directly
    //
    int sumTakeoffWait;         // sum of all takeoff wait times
    int sumLandWait;            // sum of all landing (arrival) wait times
    int numCrash;               // total number of planes crashed
    int numDepart;              // total number of planes departed
    int numArrive;              // total number of planes arrived (landed)
    int numPeopleArriveSafe;    // total number of people arrived (landed) safely (includes granchildren and family members)
    int numPeopleKilled;        // total number of people killed (includes granchildren and family members)
    int numGrandKilled;         // total number of grandchildren killed in crashes
    int numFamilyKilled;        // total number of family members killed in crashes
    int sumGrandWait;           // sum of all takeoff AND (?) landing (arrival) wait times for planes carrying grandchildren
    int sumFamilyWait;          // sum of all takeoff AND (?) landing (arrival) wait times for planes carrying family members
    double sumCargoSafe;        // sum of the value of all cargo from planes that arrived (landed) safely (and took off safely) (?)
    double sumCargoDestroyed;   // sum of the value of all cargo from planes that crashed
    int totalTime;              // sum of times for all operations UNECESSARY??
    //
    // variables used internally, not printed
    //
    int numGrand;
    int numFamily;
public:
    //
    // constructor, initialize everything to 0
    //
    Stats()
    {
        sumTakeoffWait = sumLandWait = numCrash = numDepart = numArrive = numPeopleArriveSafe = numPeopleKilled = numGrandKilled = numFamilyKilled = sumGrandWait = sumFamilyWait = sumCargoSafe = sumCargoDestroyed = totalTime = numGrand = numFamily = 0;
    };
    //
    // update all variables, called everytime a new plane arrives/departs, takes int value of time and Plane object, returns nothing
    //
    void updateAll(int, Plane);
    //
    // prints statistics, takes int value of time
    //
    void print(int);
};

///////////////////////////////////////
// UPDATE FUNCTION -- DEFINITION
///////////////////////////////////////
void updateAll(int time, Plane plane)
{
    //
    // if plane crashed, departed or arrived
    //
    if (plane.getcrashed())                     // if plane crashes, don't care if coming/going
    {
        numCrashed ++;
        numPeopleKilled += plane.getpassengers();
        numGrandKilled += plane.getgrandchildren();
        numFamilyKilled += plane.getfamily();
        sumCargoDestroyed += plane.getcargo();
    }
    else if (plane.getTypeOfFlight() == 'd')    // if taking off (departure)
    {
        numDepart ++;
        sumTakeoffWait += time - plane.getabsoluteTimeAvailableForProcessing();
        sumCargoSafe += plane.getcargo();
    }
    else if (plane.getTypeOfFlight() == 'a')    // if landing (arrival)
    {
        numArrive ++;
        sumLandWait += time - plane.getabsoluteTimeAvailableForProcessing();
        numPeopleArriveSafe += plane.getpassengers();
        sumCargoSafe += plane.getcargo();
    }
    //
    // if plane holds grandchildren and/or family members
    //
    if (plane.getgrandchildren())
    {
        sumGrandWait += (plane.getgrandchildren()) * (time - plane.getabsoluteTimeAvailableForProcessing());
        numGrand += plane.getgrandchildren());
    }
    if (plane.getfamily())
    {
        sumFamilyWait += (plane.getfamily()) * (time - plane.getabsoluteTimeAvailableForProcessing());
        numFamily += plane.getfamily());
    }
}

///////////////////////////////////////
// PRINT FUNCTION -- DEFINITION
///////////////////////////////////////
void print(int time)
{
    cout << "Average takeoff wait time: " << (sumTakeoffWait / numDepart) << endl;
    cout << "Average landing wait time: " << (sumLandWait / numArrive) << endl;
    cout << "Total number of planes crashed: " << numCrash << endl;
    cout << "Total number of planes departing: " << numDepart << endl;
    cout << "Total number of planes arriving: " << numArrive << endl;
    cout << "Total number of people landed safely: " << numPeopleArriveSafe << endl;
    cout << "Total number of people killed: " << numPeopleKilled << endl;
    cout << "Total number of grandchildren killed: " << numGrandKilled << endl;
    cout << "Total number of family killed: " << numFamilyKilled << endl;
    cout << "Average wait time for a grandchild arriving or departing: " << (sumGrandWait / numGrand)<< endl;
    cout << "Average wait time for a family member arriving or departing: " << (sumFamilyWait/ numFamily) << endl;
    cout << "Total amount of cargo that landed safely: " << sumCargoSafe << endl;
    cout << "Total amount of cargo destroyed: " << sumCargoDestroyed << endl;
    
    // need total time value (NEED TO USE SOME CLOCK)
    cout << "Total amount of time it takes to process a input file: " << time << endl;
}

#endif // to close off top if statements
