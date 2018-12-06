#ifndef O_H
#define O_H

#include<iostream>
#include"car.h"
#include<string>
using namespace std;
//class oldcar derived from class car
class oldcar:public car
{
public:
	friend ostream& operator<<(ostream& os, const oldcar& carobj);

	//default constructor with parameters
	oldcar(string cvin = "Unknown ", string cmake = "Unknown", string cmodel = "Unknown", int cyear = 0000, 
		float cprice = 0.00000, string ccategory = " Unknown", int cmileage= 0000);

	void print();				 // function that print data of the oldcar type overrided
	void set_mileage(int mile);  // function that will set the mileage of the old car
	int get_mileage();			 // function that return the mileage of the print car
private:
	int mileage; //Mileage of the old car
};

#endif

