/**
 * @file Passenger.h
 * @author Anthony Gray
 * @date  November 24, 2016
 * @class Passenger
 * This class stores the data for passengers (Name, type, seat row and priority value.
 * It also contains operators for comparisons, as well as accessor methods to retrieve 
 * those values.
 */
#ifndef PASSENGER_H
#include <string>

using namespace std;

class Passenger{
private://****************************************************************************************
	 
	 /**
	   * the priority value for the PriorityQueue
	   */
	 int key;
	 
	 /**
	   * passenger's last name
	   */
	 string name;
	 	 
	 /**
	   * passenger type, a character, where 'H' is a child or passenger who needs help in boarding,
		* 'E' is an elite passenger (frequent flyer), and 'G' is a general
	   */
	 char type;
	 
	 	 
	 /**
	   * between 1 and 26, where rows 1-4 are first class and rows 10 and 11 are exit rows
	   */
	 int row;
	 
	 	 
	 /**
	   * tracks if passenger counts as priority or general boarding
	   */
	 bool priority;
	 
public: //*******************************************************************************************
 	//CONSTRUCTORS  ---------------------------------------------------------------------------------
	
	/**
	  * default constructor
	  */
   Passenger();
	
	 /**
	   * Constructor is passed line from file, parses line and initializes data feilds
	   */
	Passenger(string line, bool genSort);


	// GETTERS ---------------------------------------------------------------------
   /**
    * gets key
    * @return key
    */
   int getKey(void);
	
	/**
    * gets name
    * @return name
    */
   string getName(void);
	
	/**
    * gets type
    * @return type
    */
   char getType(void);
	
	/**
    * gets row
    * @return row
    */
   int getRow(void);
	
	//SETTERS------------------------------------------------------------------------
	/**
    * sets key
    * @param k
    */
   void setKey(int k);
	
	/**
    * sets name
    * @param n
    */
   void setName(string n);
	
	/**
    * sets type
    * @param t
    */
   void setType(char t);
	
	/**
    * sets row
    * @param r
    */
   void setRow(int r);

	// OPERATORS---------------------------------------------------------------------
   /**
    * Defines the > operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using >
    */
   bool operator> (const Passenger &right);

   /**
    * Defines the < operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using <
    */
   bool operator< (const Passenger &right);

   /**
    * Defines the == operator for a Passenger object. 
    * @param right - right hand Passenger object for comparison 
    *                to the this Passenger object using ==
    */
   bool operator== (const Passenger &right);
}; // end Passenger
#define PASSENGER_H
#endif
