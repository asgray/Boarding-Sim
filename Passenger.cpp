/**
 * @file Passenger.cpp
 * @author Anthony Gray
 * @date November 24, 2016
 */
#include "Passenger.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/********************************************************************************************
	CONTRUCTORS
*********************************************************************************************/

// Default Constructor
Passenger::Passenger(){}//

// Parameter Constructor ----------------------------------------------------------------------
// Constructor is passed line from file, parses line and initializes data feilds 
Passenger::Passenger(string line, bool genSort){
	
	stringstream ss(line);
	// assign variables from line
	ss >> name;
	ss >> type;
	ss >> row;
	key = 1;									// default lowest key value
	
	// test for priority boarding, assign keys accordingly
	if (type == 'H'){						// test for passengers who need help
		priority = true;
		key = 7;
	}// end if else
	else if (row <= 4){					// test for 1st class
		priority = true;
		key = 6;
	}// end if else
	else if (row == 10 || row == 11 || type == 'E'){
		priority = true;					// test for frequent flyers / exit rows
		key = 5;
	}// end if
	else{
		priority = false;					// others are general boarding
	}// end else
	
	// parameter flag indicates if non-priority get sorted
	if (genSort && !priority){					// if sorting by row
		if (row <= 26 && row >= 23){
			key = 4;									// rows 23-26 board first in general boarding
		}// end if
		else if (row <= 22 && row >= 17){
			key = 3;									// rows 17-22 board second in general boarding
		}// end else if
		else if (row <= 16 && row >= 12){
			key = 2;									// rows 12-16 board third in general boarding
		}// end else if
		else if (row <= 9 && row >= 5){		// rows 10-11 are exit rows, and were already filled
			key = 1;									// rows 5-9 board last in general boarding
		}// end else if							// rows 1-4 are first class and were already filled
	}// end if 
}// end constructor -------------------------------------------------------------------------

/*******************************************************************************************
	GETTERS
*******************************************************************************************/
// used to access private data fields 
int Passenger::getKey(void){return key;}				// getKey
string Passenger::getName(void){return name;}		// getName
char Passenger::getType(void){return type;}			// getType
int Passenger::getRow(void){return row;}				// getRow

/*******************************************************************************************
	SETTERS
*******************************************************************************************/
// used to set private data fields 
void Passenger::setKey(int k){key = k;}				//setKey
void Passenger::setName(string n){name = n;}			//setName
void Passenger::setType(char t){type = t;}			//setType
void Passenger::setRow(int r){row = r;}				//setRow

/********************************************************************************************
	Operators 
********************************************************************************************/
bool Passenger::operator> (const Passenger &right){
   return (key > right.key);
}// end > -------------------------------

bool Passenger::operator< (const Passenger &right){
   return (key < right.key);
}// end < -------------------------------

bool Passenger::operator== (const Passenger &right){
   return (key == right.key);
}// end == --------------------------------