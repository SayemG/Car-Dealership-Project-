#ifndef n_h
#define n_h

#include "car.h" 
#include<iostream>
#include<string>
using namespace std;

// class new car derived from class car
class newcar : public car
{
public:
	friend ostream& operator<<(ostream& os, const newcar& carobj);

	// default constructor with parameters
	newcar(string cvin = "Unknown ", string cmake = " Unknown", string cmodel = " Unknown", int cyear = 0000,
			float cprice = 0.00000, string ccategory = " Unknown",string nc_warrenty="Unknown");

	void set_warrenty(string nc_warnty); //function that set the warrent provider of the new car
	string get_warrenty();               // function that return the name of the warrenty provider
	void print();

private:
	string nc_warrenty;  // warrenty of the new car
};
#endif


