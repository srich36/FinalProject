//
// Created by sean on 4/23/18.
//

#ifndef FINALPROJECT_INPUT_H
#define FINALPROJECT_INPUT_H


#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#define DATASIZEMAX 8
#include "Plane.h"

using namespace std;

class input {
private:
    string command, action;
    int time, fuel, people, family, grand;
    double cargo;
public:
    //Process function takes string lineinput as parameter. Returns nothing.
    //Takes lineinput string and parses it.
    void process(string lineinput) {
        string arry[DATASIZEMAX];
        int count = 0;
        for (int i = 0; i < DATASIZEMAX; i++) {
            arry[i] = "";
        }
        string parse = "";

        //Goes through line and if character is a letter, number, or period, add to parse string.
        //When character is not a letter, number, or period, ie. a comma, put parse string into array. Set parse string to empty.
        for (int i = 0; i < lineinput.size(); i++) {
            if (isalpha(lineinput[i]) || isdigit(lineinput[i]) || lineinput[i] == '.') {
                parse += lineinput[i];
                int j = i + 1;
                while (isalpha(lineinput[j]) || isdigit(lineinput[j]) || lineinput[j] == '.') {
                    parse += lineinput[j];
                    j++;
                }
                i = j;
                arry[count] = parse;
                count++;
                parse = "";
            }
        }
        //Command will always be the first element of the array.
        command = arry[0];
        //If data command, set variables equal to rest of elements in array.
        if (command == "D") {
            time = stoi(arry[1]);
            action = arry[2];
            fuel = stoi(arry[3]);
            people = stoi(arry[4]);
            cargo = stoi(arry[5]);
            family = stoi(arry[6]);
            grand = stoi(arry[7]);
        }
            //If the command is W or P, we null the rest of the values.
        else {
            time = NULL;
            action = "";
            fuel = NULL;
            people = NULL;
            cargo = NULL;
            family = NULL;
            grand = NULL;
        }

    }

    //Below are get functions. Use object.get*** in main class to call these values.
    string getCommand() {
        return command;
    }
    int getTime() {
        return time;
    }
    string getAction() {
        return action;
    }
    int getFuel() {
        return fuel;
    }
    int getPeople() {
        return people;
    }
    double getCargo() {
        return cargo;
    }
    int getFamily() {
        return family;
    }
    int getGrand() {
        return grand;
    }

};



#endif //FINALPROJECT_INPUT_H
