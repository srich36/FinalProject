//
// Created by sean on 4/23/18.
//

#ifndef FINALPROJECT_PLANESTATS_H
#define FINALPROJECT_PLANESTATS_H


#include "Plane.h"              // to use Sean's plane class
#include <time.h>                 // to get runtime (needed for print function) ACTUALLY USE

#include <iostream>
using namespace std;

///////////////////////////////////////
// CLASS -- DEFINITION
///////////////////////////////////////
class PlaneStats
{
private:
    //
    // variables to be printed directly
    //
    clock_t tstart;
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
    PlaneStats()
    {
        tstart = clock();
        sumTakeoffWait = sumLandWait = numCrash = numDepart = numArrive = numPeopleArriveSafe = numPeopleKilled = numGrandKilled = numFamilyKilled = sumGrandWait = sumFamilyWait = sumCargoSafe = sumCargoDestroyed = totalTime = numGrand = numFamily = 0;
    };
    //
    // update all variables, called everytime a new plane arrives/departs, takes int value of time and Plane object, returns nothing
    //
    void updateAll(int, Plane);
    //
    // prints statistics, takes int value of time
    //
    void print();
};

///////////////////////////////////////
// UPDATE FUNCTION -- DEFINITION
///////////////////////////////////////
void PlaneStats::updateAll(int time, Plane plane1)
{
    //
    // if plane crashed, departed or arrived
    //
    if (plane1.getcrashed())                     // if plane crashes, don't care if coming/going
    {
        numCrash++;
        numPeopleKilled += plane1.getpassengers();
        numGrandKilled += plane1.getgrandchildren();
        numFamilyKilled += plane1.getfamily();
        sumCargoDestroyed += plane1.getcargo();
    }
    else if (plane1.getTypeOfFlight() == "d" || plane1.getTypeOfFlight() == "D")    // if taking off (departure)
    {
        numDepart ++;
        sumTakeoffWait += (time - plane1.getabsoluteTimeAvailableForProcessing());
        sumCargoSafe += plane1.getcargo();
    }
    else if (plane1.getTypeOfFlight() == "a" || plane1.getTypeOfFlight() == "A") // if landing (arrival)
    {
        numArrive ++;
        sumLandWait += (time - plane1.getabsoluteTimeAvailableForProcessing());
        numPeopleArriveSafe += plane1.getpassengers();
        sumCargoSafe += plane1.getcargo();
    }
    //
    // if plane holds grandchildren and/or family members
    //
    if (plane1.getgrandchildren())
    {
        sumGrandWait += (plane1.getgrandchildren()) * (time - plane1.getabsoluteTimeAvailableForProcessing());
        numGrand += plane1.getgrandchildren();
    }
    if (plane1.getfamily())
    {
        sumFamilyWait += (plane1.getfamily()) * (time - plane1.getabsoluteTimeAvailableForProcessing());
        numFamily += plane1.getfamily();
    }
}

///////////////////////////////////////
// PRINT FUNCTION -- DEFINITION
///////////////////////////////////////
void PlaneStats::print()
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
    cout << "Total runtime for this input file: " << (double)(clock() - tstart)/CLOCKS_PER_SEC << " seconds" << endl;
}



#endif //FINALPROJECT_PLANESTATS_H
