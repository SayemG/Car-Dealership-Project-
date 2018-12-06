#include "car.h"
#include<vector>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

//defination of the constructor
car::car(string cvin, string cmake, string cmodel, int cyear, float cprice, string ccategory)
{
	VIN = cvin;
	make = cmake;
	model = cmodel;
	year = cyear;
	price = cprice;
	category = ccategory;
}

//Defination of the overloading function operator<< for vectorType object
ostream& operator<<(ostream& os, const vector<car> carlist55)
{
	for (int i = 0; i < carlist55.size(); i++)
		os << carlist55[i] << endl;
	os << "\n";
	return os;
}
// defination of the overloading function operator<<  for cartype object
ostream& operator<<(ostream& os, const car& carobj)
{
	os << carobj.VIN << " ";
	os << carobj.make << " ";
	os << carobj.model << " ";
	os << carobj.year << " ";
	os << carobj.price << " ";
	os << carobj.category << " ";

	return os;
}


//defination of al setters functions
void car::set_VIN(string cvin)
{
	VIN=cvin ;
}

void car::set_make(string cmake)
{
	make= cmake;
	
}
void car::set_model(string cmodel)
{
	model= cmodel;

}
void car::set_year(int cyear)
{
	year=cyear;
	
}
void car::set_price(float cprice)
{
	price= cprice;
}
void car::set_catagory(string ccategory)
{
	category=ccategory;
}

//definations of all getter functions

string car::get_VIN()
{
	return VIN;
}
string car::get_make()
{
	return make;
}
string car::get_model()
{
	return model;
}
int car::get_year()
{
	return year;
}
float car::get_price()
{
	return price;
}
string car::get_catagory()
{
	return category;
}

// defination print function
void car::print()  
{
	cout <<left<< fixed<<showpoint<< setprecision(2);

	cout << left <<fixed<< setw(15) << VIN << setw(15) << make << setw(25) << model <<
		setw(15) << year << setw(15) << price << setw(15) << category;

	/*cout << "Car VIN:" << VIN  << endl;
	cout << "Car Make:" << make << endl;
	cout << "Car Model:" << model << endl;
	cout << "Car Year:" << year << endl;
	cout << "Car Price:" << price << endl;
	cout << "Car Category:" << category<< endl; 
	*/
} 






