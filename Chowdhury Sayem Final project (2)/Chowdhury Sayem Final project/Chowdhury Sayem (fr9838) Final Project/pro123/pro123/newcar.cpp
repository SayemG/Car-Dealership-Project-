#include "newcar.h"
#include"car.h"
//--------------------------



#include<iostream>
#include<string>
using namespace std;
#include<iomanip>

//defination of default constructor
newcar::newcar(string cvin, string cmake, string cmodel, int cyear, float cprice, string ccategory, string nc_warr) 
	:car(cvin, cmake, cmodel, cyear, cprice,ccategory)
{
	nc_warrenty = nc_warr;
}

//defination of print function
void newcar::print()
{
	car::print();
	cout << fixed<<showpoint<<left<<"0.00000             "<<setw(18)<< nc_warrenty << endl;

}
// defination of the function set warrenty
void newcar::set_warrenty(string ncwy)
{
	nc_warrenty = ncwy;

}

string newcar::get_warrenty()
{
	return nc_warrenty;
}


 
ostream& operator<<(ostream& os, const newcar& carobj)
{
	os << carobj.nc_warrenty;
	return os;
}

