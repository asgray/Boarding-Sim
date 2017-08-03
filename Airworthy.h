/**
 * @file Airworthy.h
 * @author Anthony Gray
 * @date  November 24, 2016
 * @class Airworthy
 * This class contains two heap queues to store airline passengers by priority,
 * as well as methods for loading and unloading the queues from and to data files.
 */
#ifndef AIRWORTHY_H
#include <string>
#include "Heap_PriorityQueue.h"
#include "Passenger.h"

using namespace std;

class Airworthy{
private://****************************************************************************************
	 
	 //DATA FIELDS --------------------------------------------------------------------------------
	 /**
	   * Queue where priority is set using Airworthy's previous boarding procedure
	   */ 
	 Heap_PriorityQueue<Passenger> previous;
	 
	 	 
	 /**
	   * Queue where priority is set using Airworthy's new random boarding procedure
	   */
	 Heap_PriorityQueue<Passenger> random;
	 
	 	 
	 /**
	   * the amount of time, in seconds, required to board a plane using Airworthy's previous boarding procedure
	   */
	 int boardTime;
	 
	 //PRIVATE METHODS -----------------------------------------------------------------------------------------
	 /**
	   * Reads data from input file, loads queues, writes contents of queues to output file
		* @param string file, string outputName
      * @throws none
      * @return none
	   */
	 void loadHeaps (const string& file, const string& outputName);
	 	 
	 /**
	   * Empties queue, writes data to output file, and increments boardTime based on the last item's position
		* @param Heap_PriorityQueue<Passenger> queue, string outputName
      * @throws none
      * @return none
	   */
	 void boarding(Heap_PriorityQueue<Passenger>& queue, const string& outputName);
	 
	 /**
	   * calculates total minutes from seconds, casts to doulble
		* @param none
      * @throws none
      * @return double minutes
	   */
	 double displayTime(void);
	 
public: //*******************************************************************************************
 	
	//CONSTRUCTORS  -----------------------------------------------
	/**
	  * default constructor
	  */
   Airworthy();
			 
	 /**
	   * constructor accpets names of input and output files
		* @param string fileName, string outputName
	   */
	Airworthy(const string& fileName, const string& outputName);
	
	//PUBLIC METHOD--------------------------------------------------------
	 /**
	   * opens output file and writes simulation results of both queues to it
		* @param string outputName
      * @throws none
      * @return none
	   */
	void simulateBoarding(const string& outputName);
	
}; // end Airworthy
#define AIRWORTHY_H
#endif
