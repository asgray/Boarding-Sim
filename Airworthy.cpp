/**
 * @file Airworthy.cpp
 * @author Anthony Gray
 * @date November 24, 2016
 */
#include "Airworthy.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/********************************************************************************************
	CONTRUCTORS
*********************************************************************************************/

// Default Constructor
Airworthy::Airworthy(){}//

// Parameter Constructor--------------------------------------------------
// constructor accpets names of input and output files
Airworthy::Airworthy(const string& fileName, const string& outputName){
	loadHeaps(fileName, outputName); // populates heaps with data from file
}//end  parameter constructor---------------------------------------------

/******************************************************************************************
	METHODS
******************************************************************************************/

// loadHeaps()----------------------------------------------------------------------------
// Reads data from input file, loads queues, writes contents of queues to output file
void Airworthy::loadHeaps (const string& file, const string& outputName){
	
	string passLine; 								// input string from file
	ifstream inFile(file); 						// declare and open the input file
   ofstream outFile(outputName);					// declare and open the output file
	
	if (!inFile){										// check for input
      cout << "Error opening file for input: " << file << endl
		<< "Heap Queues not populated" << endl;// error message
 	}// end if  
	else if (!outFile){								// check for output
		 cout << "Error opening file for output: " << file << endl
		<< "Input not saved" << endl;				// error message
	}// end else if
	else{													// with both files open
		outFile << "Passenger List" << endl << "Name       Type  Row"
		<< endl << "---------------------" << endl;
      while (!inFile.eof()){
         getline (inFile, passLine);			// get input string
			if (!passLine.empty()){					// ignore empty lines
				Passenger p(passLine, true);		// new passenger, with general sorting
				Passenger q(passLine, false);		// new passenger, only priority sorting
				previous.add(p);						// add full sort to previous
				random.add(q);							// add unsorted to random
															// write data fields to file
				outFile << left << setw(13)<<  p.getName() << 
				p.getType() << right << setw(4)<< p.getRow() << endl;
			}// end if
      }// end while
      inFile.close();								// close both files
		outFile.close();
   }//end else
}//end loadHeaps()-----------------------------------------------------------------------

// simulateBoarding()--------------------------------------------------------------------
// opens output file and writes simulation results of both queues to it
void Airworthy::simulateBoarding(const string& outputName){
	
	ofstream outFile(outputName, ios_base::app);	// reopen output file for writing
	
	if (!outFile){											// check for output
      cout << "Error opening file for output: " << outFile << endl
		<< "Simulation not saved" << endl;			// error message
 	}// end if
	else {													// if output successful
	outFile << endl<< "Ordered General Boarding" << 
	endl << "Name       Type  Row  Key"				// print data headers
	<< endl << "--------------------------" << endl;
	boarding(previous, outputName);					// simulate with ordered general boarding
	
	outFile << "Random General Boarding" <<
	endl << "Name       Type  Row  Key"				// print data headers
	<< endl << "--------------------------" << endl;
	boarding(random, outputName);						// simulate with random general boarding
	} // end else
	outFile.close();										// close output file
}//end simulateBoarding()-------------------------------------------------------------------

// boarding()--------------------------------------------------------------------------------------------
// Empties queue, writes data to output file, and increments boardTime based on the last item's position
void Airworthy::boarding(Heap_PriorityQueue<Passenger>& queue, const string& outputName){
	
	ofstream outFile(outputName, ios_base::app);	// reopen output file
	
	if (!outFile){											// check for output
      cout << "Error opening file for output: " << outFile << endl
		<< "Simulation not saved" << endl;			// error message
 	}// end if
	else {													// if output successful
	outFile << fixed << setprecision(2);			// format doubles
	boardTime = 0;									// reset counter, priority boarding always happens first
	int prevRow = 27;								// tracks if passenger will be blocked, set out of row range
	while (!queue.isEmpty()){							
		Passenger p = queue.peek();			// retrieve passenger
		int boardRow = p.getRow();				// get passenges's row
		if (prevRow <= boardRow){				// if blocked, time +25sec
			boardTime += 25;
		}// if
		else {										// if not blocked time +1sec
			boardTime++;
		}// else
		prevRow = boardRow;						// this passenger blocks next passenger
														// ordered output written to file
		outFile << left << setw(14)<<  p.getName() << 
		p.getType() << right << setw(5)<< p.getRow()
		 << setw(3) << p.getKey() << endl;
		queue.remove();							// dequeue
	}//while											// display total time in minutes
	outFile << "Boarding took " << displayTime() << " minutes." << endl << endl;
	}// end else
	outFile.close();								// close output file
}// end boarding()-------------------------------------------------------------------------------------------

// displayTime()-------------------------------------------
// calculates total minutes from seconds, casts to doulble
double Airworthy::displayTime(void){
	double minutes = double (boardTime) /60;
	return minutes;
}//end displayTime()---------------------------------------

