/*
 Creating class for statistics
 
 Note) Arrive means same thing as land
 
----------------------------------------------------------------------------------------------------------------------------
 Need:
 • Average takeoff wait time
 - function to sum up TAKEOFF wait times, divide by total number of wait times
 
 • Average landing wait time
 - function to sum up LANDING wait times, divide by total number of wait times
 
 • Total number of plane crashes
 - function to increment every time there is a plane crash
 
 • Total number of planes departing
 - function to increment every time a plane departs
 
 • Total number of planes arriving
 - function to increment every time a plane arrives
 
 • Total number of people that landed safely
 - function to add the number of people/plane to counter for every plane that lands
 
 • Total number of people killed
 - function to add the number of people/plane to counter for every plane that crashes
 
 • Total number of Grandchildren killed
 - function to sum the number of grandchildren/plane for every plane that crashes
 
 • Total number of Family killed
 - function to sum the number of family/plane for every plane that crashes
 
 • Average wait time for a grandchild arriving or departing (Dead grandchildren not included)
 - function to sum wait times for planes carrying grandchildren (add both arrival wait times and departure wait times) divide by number of weight times
 
 • Average wait time for a family member arriving or departing (Dead family not included)
 - function to sum wait times for planes carrying grandchildren (add both arrival wait times and departure wait times) divide by number of weight times
 
 • Total amount of cargo that landed safely
 - function to sum the price of cargo/plane for every plane that lands safely
 
 • Total amount of destroyed Cargo
 - function to sum the price of cargo/plane for every plane that crashes
 
 • Total amount of time it takes to process a input file
 - function to sum total amount of time taken for entire input file
 
 ALSO NEED PRINT FUNCTION
 - function to call all above functions and print their values with accompanying labels
 
----------------------------------------------------------------------------------------------------------------------------
 
 Important consideration: which variables to include
 - want to include variables that will make job of functions easy
 
 Do I need function to intialize all variables to 0? YES
 - ex) to account for case where no planes crash, want numCrash == 0
 
----------------------------------------------------------------------------------------------------------------------------
 
 updateAll(Plane) function outline:
 if plane has crashed:
    numCrash ++
    numPeopleKilled += (number of people on plane)
    numGrandKilled += (number of grandchildren on plane)
    numFamilyKilled += (number of family on plane)
    sumCargoDestroyed += (amount of cargo on board)
 
else if plane has departed:
    numDepart ++
    sumTakeoffWait += (amount of time plane has been waiting before takeoff)
 
 else if plane has arrived:
    numArrive ++
    sumLandWait += (amount of time plane has been waiting to land)
    numPeopleArriveSafe += (number of people on plane)
    sumCargoSafe += (amount of cargo on board)
 
 (Note: if crashed, don't care if it was a departure or landing)
 (Note: need to calculate individual plane wait times in stats class)
    (wait time) = (current time) - (getrequestAvailableForProcessing())
 
 
 
 */


#ifndef FINALPROJECT_STATS_H    // since .h file
#define FINALPROJECT_STATS_H    // defines file

//#include "stdafx.h"           // needed for VS
#include "Plane.h"              // to use Sean's plane class

#include <iostream>
using namespace std;

class Stats
{
//
// hold variables
//
private:
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
    int totalTime;              // sum of times for all operations
    
//
// holds functions
//
public:
    // constructor, initialize everything to 0
    Stats()
    {
        sumTakeoffWait = sumLandWait = numCrash = numDepart = numArrive = numPeopleArriveSafe = numPeopleKilled = numGrandKilled = numFamilyKilled = sumGrandWait = sumFamilyWait = sumCargoSafe = sumCargoDestroyed = totalTime = 0;
    };
    
    // update all variables, called everytime a new plane arrives/departs, takes in/returns nothing
    void updateAll();
    
    // prints statistics
    void print();
};


//
// update all variables, called everytime a new plane arrives/departs, takes in/returns nothing
//
void updateAll()
{
    if (Plane.getcrashed())                // if plane crashes, don't care if coming/going
    {
        numCrashed ++;
        numPeopleKilled += Plane.getpassengers();
        numGrandKilled += Plane.getgrandchildren();
        numFamilyKilled += Plane.getfamily(); // currently not a function in plane class
        sumCargoDestroyed += Plane.getcargo();
    }
    else if (Plane.getTypeOfFlight() == 'd') // if taking off (departure)
    {
        numDepart ++;
        //sumTakeoffWait += (amount of time plane has been waiting before takeoff)  // figure out wait time first
    }
    else if (Plane.getTypeOfFlight() == 'l') // if landing (arrival)
    {
        numArrive ++;
        //sumLandWait += (amount of time plane has been waiting to land)    // figure out wait time first
        numPeopleArriveSafe += Plane.getpassengers();
        sumCargoSafe += Plane.getcargo();
    }
}


//
// prints statistics
//
void print()
{
    cout << "Average takeoff wait time: " <<____<< endl;
    cout << "Average landing wait time: " <<____<< endl;
    cout << "Total number of planes crashed: " << numCrash << endl;
    cout << "Total number of planes departing: " << numDepart << endl;
    cout << "Total number of planes arriving: " << numArrive << endl;
    cout << "Total number of people landed safely: " << numPeopleArriveSafe << endl;
    cout << "Total number of people killed: " << numPeopleKilled << endl;
    cout << "Total number of grandchildren killed: " << numGrandKilled << endl;
    cout << "Total number of family killed: " << numFamilyKilled << endl;
    
    // need to divide by total number of planes holding grandchildren, family
    cout << "Average wait time for a grandchild arriving or departing: " << sumGrandWait/?? << endl;
    cout << "Average wait time for a family member arriving or departing: " << sumFamilyWait/?? << endl;
    
    cout << "Total amount of cargo that landed safely: " << sumCargoSafe << endl;
    cout << "Total amount of cargo destroyed: " << sumCargoDestroyed << endl;
    
    // need total time value (from ATC?)
    cout << "Total amount of time it takes to process a input file: " <<_____<< endl;
    
    
}

#endif // to close off top if statements
