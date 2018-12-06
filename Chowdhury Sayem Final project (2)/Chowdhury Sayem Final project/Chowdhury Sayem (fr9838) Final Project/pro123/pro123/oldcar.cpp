#include<iostream>
#include "oldcar.h"
#include<string>
#include<iomanip>
using namespace std;

//defination of default constructor
oldcar::oldcar(string cvin, string cmake, string cmodel, int cyear, float cprice, string ccategory, int cmileage)
	:car(cvin, cmake, cmodel, cyear, cprice, ccategory)
{
	mileage = cmileage;
}

// defination of the print that override for class oldcar
void oldcar::print()
{
	car::print();
	cout <<showpoint<< setprecision(2);
	cout <<showpoint<< fixed<<left<<setw(15)<< mileage <<"     None" <<endl;
} 
//function defination that set the mileage of the car 
void oldcar:: set_mileage(int mile)
{
	mileage = mile;
}

// function defination that return the  mileage of the car
 int oldcar:: get_mileage()
{
	return mileage;
}

ostream& operator<<(ostream& os, const oldcar& carobj)
{
	os << carobj.mileage;
	return os;
}



