#ifndef C_H
#define C_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//class car 
class car
{
//public members variables of car
public:
	friend ostream& operator<< (ostream& os, const vector<car>&carlist55); // function that overload the insertion operator for the vector object

	//[ Prototype of overloading function operator<< ]
	friend ostream& operator<<(ostream& os, const car& cobj); //function that overload the insertion operator for car object
	
//All setter functions
	void set_VIN(string cvin);            //fnction set the VIN number of the car
	void set_make(string cmake);          //fnction set the Make of the car
	void set_model(string cmodel);        //fnction set the Model number of the car
	void set_year(int cyear);             //fnction set the  Year of the car
	void set_price(float cprice);         //fnction set the Price number of the car
	void set_catagory(string ccategory);  //fnction set the Category number of the car

//All getter functions
	 string get_VIN();		 //Function return the VIN number of the car
	 string get_make();	     //Function return the Make of the car
	 string get_model();	 //Function return the Modelof the car
	 int get_year();		 //Function return the Year of the car	
	 float get_price();		 //Function return the Price of the car	
	 string get_catagory();	 //Function return the Category of the car

//Virtual  print function 
	virtual void print();


// Default constructor with parameter
	car(string cvin = "Unknown ", string cmake = " Unknown", string cmodel = " Unknown", int cyear = 0000, 
			float cprice = 0.00000, string ccategory = " Unknown");

//private member variables of the class car
private: 
	string VIN;			// vin number of the car
	string make;		// company name of the car  like Toyota, GM
	string model;		// model of the car Corolla, chevrolet
	int year;			// year of the car built
	float price;		// price of the car
	string category;	// car category new or old 
};

//
#endif

