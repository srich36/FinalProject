/*
 Creating class for statistics
 
 Arrive means same thing as land
 
 --------------------------------------------------------------------------------------------------------------------------------------------------------------
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
 --------------------------------------------------------------------------------------------------------------------------------------------------------------

 Important consideration: which variables to include
    - want to include variables that will make job of functions easy
 
 Do I need function to intialize all variables to 0?
    - ex) to account for case where no planes crash, want numCrash == 0
 
 
 
*/


//#include "stdafx.h" // needed for VS
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
    int avgWait();
    void print();
    
};

//
// prints stats
//
void print()
{

}






