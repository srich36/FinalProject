//
// Created by sean on 4/23/18.
//

#ifndef FINALPROJECT_QUEUE_H
#define FINALPROJECT_QUEUE_H

//

/**************************************************************************************************
* Description: This file contains the class LinkedList which implements a data structure of
*			   variable length and methods to alter that array.
*
* Contact:
* Erica Venkatesulu (exv5064@psu.edu) (215-808-5008)
*
* Functions declared in the file:
*           Constructor:     This method creates a new linked list.
*			addElementFront: This method adds an element to the front of the linked list.
*			addElementBack:  This method adds an element to the end of the linked list.
*			insertElement:   This method adds an element to the linked list at the specified index.
*			deleteElement:   This method deletes the first instance of an element.
*			removeFront:     This method deletes the first element from the linked list.
*			removeBack:      This method deletes the last element from the linked list.
*           swap:            This method takes two indices and swaps the elements in those indices.
*			size:            This method returns the length of the linked list.
*			print:           This method prints all the elements in the linked list.
*
* Revision History:
*  Who                 Date        Issue                   Description
*  -----------         ---------   ---------------------   ---------------------
*  Erica Venkatesulu   3-11-18	   ????				       Initial Version
*  Erica Venkatesulu   4-22-18     Swap and sort added     First modification for final project
*
* Limitations:
*  Aborts if indices out of range are passed into function (developed in a design by contract way)
**************************************************************************************************/

//
// Include files
//
#include <stdio.h>
#include <iostream>
#include <string>
#include "Plane.h"

using namespace std;

//
// Declare global variables
//
string userin = "";

//
// structure definition
//
typedef struct node {
    Plane *plane1; // to be changed to a plane pointer
    node*next;
    node*prev;
} node;


//
// Define the class for LinkedList
//
class Queue
{
public:
    //
    // Constructors - declares a new dynamic array with length 1 and the only element initialized to 0
    //
    Queue()
    {
        cout << "creating a new array" << endl;
        first = 0;
        last = 0;
        arrsize = 0;
    }

    //
    // Declare public methods
    //

    //
    // Add Element Front - This method adds the value passed in to the front of the array
    //
    void                            // OUT: none
    addElementFront(Plane *newPlane)   // IN:  the value to be added to the array //needs to be changed to a plane
    {
        //
        // Declare local variables
        //
        node *temp = new node;

        temp->plane1 = newPlane;
        if (first == 0)
        {
            first = temp;
            last = temp;
            temp->prev = 0;
            temp->next = 0;
        }
        else
        {
            temp->next = first;
            first->prev = temp;
            temp->prev = 0;
            first = temp;
        }
        arrsize++;
        return;
    }

    node* getFirst(){
        return first;
    }

    //
    // Add Element Back - This method adds the value passed in to the front of the array
    //
    void                           // OUT: none
    addElementBack(Plane *newPlane)   // IN:  the value to be added to the array
    {
        //
        // Declare local variables
        //
        node *temp = new node;

        temp->plane1 = newPlane;
        if (first == 0)
        {
            first = temp;
            last = temp;
            temp->prev = 0;
            temp->next = 0;
        }
        else
        {
            last->next = temp;
            temp->prev = last;
            temp->next = 0;
            last = temp;
        }
        arrsize++;
        return;
    }

    //
    // Insert Element - This method adds the value passed in at the specified index
    //
    void                                     // OUT: none
    insertElement(int index, Plane *newPlane)   // IN:  the index at which to add a value and the value to add
    {
        //
        // Declare local variables
        //
        node *temp = new node;
        temp = first;
        node *temp2 = new node;
        temp2->plane1 = newPlane;

        if (index == 0)
        {
            addElementFront(newPlane);
        }
        else if (index == arrsize)
        {
            addElementBack(newPlane);
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp2->prev = temp->prev;
            temp2->next = temp;
            temp->prev = temp2;
            (temp2->prev)->next = temp2;
            arrsize++;
        }

        return;
    }

    //
    // Delete Element - This method deletes the first instance of the value passed into it
    //
    bool                           // OUT: boolean of whether the delete was successful
    deleteElement(Plane *deletedPlane)    // IN:  the value to delete the first instance of
    {
        //
        // Declare local variables
        //
        bool delsuccess = false;
        node *temp = new node;
        temp = first;

        while ((temp != 0) && !delsuccess)
        {
            if ((temp->plane1) == deletedPlane)
            {
                if (temp == first)
                {
                    removeFront();
                }
                else if (temp == last)
                {
                    removeBack();
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp->next = 0;
                    temp->prev = 0;
                    arrsize--;
                }


                delsuccess = true;
            }
            temp = temp->next;
        }

        return delsuccess;
    }

    //
    // Remove Front - This method deletes the first element of the array
    //
    void               // OUT: NONE
    removeFront()  // IN:  NONE
    {
        if (arrsize > 1)
        {
            first = first->next;
            delete first->prev->plane1;
            delete (first->prev);
            first->prev = 0;
            arrsize--;
        }
        else if (arrsize == 1)
        {
            delete first->plane1;
            delete first;
            first = 0;
            last = 0;
            arrsize--;
        }
        return;
    }

    //
    // Remove Back - This method deletes the last element of the array
    //
    void               // OUT: NONE
    removeBack()   // IN:  NONE
    {
        if (arrsize > 1)
        {
            last = last->prev;
            delete last->next->plane1;
            delete (last->next);
            last->next = 0;
            arrsize--;
        }
        else if (arrsize == 1)
        {
            delete last->plane1;
            delete last;
            first = 0;
            last = 0;
            arrsize--;
        }
        return;
    }

    //
    // Sort - this sorts the planes in the linked list by priority
    //
    void
    sort()
    {
        node *tempi = last;
        node *tempj = first;
        for (int i = arrsize-1; i > 0; i--)
        {
            tempj = first;
            for (int j = 1; j <= i; j++)
            {
                if (tempj->plane1->getpriority() < tempj->next->plane1->getpriority())
                {

                    Plane *temp = tempj->next->plane1;
                    tempj->next->plane1 = tempj->plane1;
                    tempj->plane1 = temp;
                }
                tempj = tempj->next;
            }
            tempi = tempi->prev;
        }

    }

    //
    // Size - This method returns the size of the array
    //
    int           // OUT: the size of the array
    size()    // IN:  none
    {
        return arrsize;
    }

    //
    // Print - This prints all of the elements in the array
    //
    void               // OUT: none
    print(bool DEBUG)	       // IN:  none
    {

        //
        // Declare local variables
        //
        node *temp = first;

        if(DEBUG){
            while (temp != 0)
            {
                cout << "Printing out the queue to debug " << endl;
                cout << "Plane attributes are as follows: " << endl;
                cout << "Priority: " << temp->plane1->getpriority() << endl;
                cout << "Action: " << temp->plane1->getTypeOfFlight() << endl;
                cout << "Absolute time request is available " << temp->plane1->getabsoluteTimeAvailableForProcessing() << endl;
                cout << "************************************************" << endl;
                temp = temp->next;
            }

        }
        else {

            while (temp != 0) {
                cout << temp->plane1->getpriority() << " ";
                temp = temp->next;
            }
            cout << endl;

            temp = 0;
            delete temp;
        }

        return;
    }

private:
    //
    // Declare private variables
    //
    node *first = new node;
    node *last = new node;
    int arrsize = 0;  // the constructor creates an array with 0 elements, so that is the default

};

/*int main()
{
	////
	////declare local variables
	////
	//string command; // first part of user input
	//string num = "not a num"; // second part of user input
	//						  // below are variables used for interpreting and error checking user input
	//int num_1;
	//string strnum_1;
	//int num_2;
	//string strnum_2;
	//bool validuserin;

	//cout << "test starts here" << endl;
	//LinkedList temptest = LinkedList();
	//temptest.addElementBack(4);
	//temptest.addElementBack(5);
	//temptest.addElementBack(6);
	//temptest.addElementBack(7);
	//temptest.addElementBack(8);
	//temptest.print();
	//cout << "sort" << endl;
	//temptest.sort();
	//temptest.print();

	//LinkedList temptest2 = LinkedList();
	//temptest2.addElementBack(3);
	//temptest2.addElementBack(5);
	//temptest2.addElementBack(4);
	//temptest2.addElementBack(2);
	//temptest2.addElementBack(1);
	//temptest2.print();
	//temptest2.sort();
	//temptest2.print();

	//LinkedList test3 = LinkedList();
	//test3.addElementFront(5);
	//test3.addElementFront(5);
	//test3.addElementFront(3);
	//test3.addElementFront(3);
	//test3.addElementFront(5);
	//test3.print();
	//test3.sort();
	//test3.print();

	return 0;
}
*/
#endif //FINALPROJECT_QUEUE_H
