/**
 * @file SimulationProject.h
 * @author Anthony Gray
 * @date  November 24, 2016
 * This file contains the main method that will decribe how the program operates,
 * then run a boarding simulation for each file of passenger data provided.
 */
#include "Airworthy.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// description()---------------------------------------------------------------------
/*provides a detailed description for the user, explaining what the program is doing, 
how it works, and the location of all output files.*/
void description(void){
	cout << "This program will collect passenger information from a series of data files and" << endl
	<< "simulate those passengers boarding an Airbus A320-200 plane. The simulations" << endl
	<< "will compare the time it takes for all the passengers to board under the old" << endl
	<< "boarding system to the time it takes for all the passengers to board under " << endl
	<< "the new system. In both cases, the priority passengers (disabled, first class," << endl
	<< "frequent flyers and passengers seated in exit rows) will board first, followed " << endl
	<< "by the non-priority, or general boarding passengers. Under the old system, " << endl
	<< "general boarding is split into four groups based on seat row number, while " << endl
	<< "under the new system, all general boarding is conducted as a single group. " << endl
	<< "The results of the simulations will be recorded in text files located in " << endl
	<< "the same directory as the executible file. The files will contain a list of all " << endl
	<< "the passengers in the order that they arrived, followed by lists of those " << endl
	<< "passengers in the order in which they boarded the plane under each boarding" << endl
	<< "system. The time it took for all the passengers to board will be located at" << endl 
	<< "the bottom of each list." << endl << endl;
}// end description()---------------------------------------------------------------

//main()~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main (void){
	
	description();							// Describe the program to the user
	
	int numTests = 3;						// variable for loop, = to number of files to read and create
	
	//open and close all the input and output files
	string inFiles[numTests] = {"Airworthy70.txt","Airworthy85.txt","Airworthy100.txt"};	// input file names
	string outFiles[numTests] = {"results70.txt","results85.txt","results100.txt"};	 		// input file names

	for (int i = 0; i < numTests; i++){			// repeat for all files
		cout << "Simulating boarding from " << inFiles[i] << "." << endl;
		Airworthy test(inFiles[i], outFiles[i]);	// load queues, creat outputs
		test.simulateBoarding(outFiles[i]);			// run simulations, add to outputs
	}// for	
					
   return EXIT_SUCCESS;
}// end main()~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~