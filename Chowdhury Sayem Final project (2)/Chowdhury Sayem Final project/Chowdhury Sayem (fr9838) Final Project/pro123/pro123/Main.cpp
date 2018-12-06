#ifndef m_h
#define m_h
// Header files
#include<iostream>
#include<cctype>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#include"car.h"
#include"newcar.h"
#include"oldcar.h"
using namespace std;

// Functions prototypes
void convert_string(string& st);
void addCar(vector<car*> &carlist1);
void catalog123(vector<car*>&carlist2);
void Search_D_Inventory(vector<car*>&carlist3);
void sell_car(vector<car*>&carlist4);
void returnCar(vector<car*>&carlist5);
void show_car_within_prange(vector <car*>&carlist6);
void print_data_into_file(vector<car*> &carlist7);
void read_data_from_file(vector<car*> &carlist8);

//
int main()//main function
{
	cout << fixed << showpoint << setprecision(2);
	vector<car*>carList123; // vector object or container

	//fill up the vectorlist with car objects///
	//-------------------------------------------
	newcar* Toyota = new newcar("3310", "TOYOTA", "COROLLA", 2017, 28000.00, "NEW", "MUSA");
	carList123.push_back(Toyota);
	oldcar* GM = new oldcar("8810", "GM", "SAFARI", 2016, 5999.00, "OLD", 91000);
	carList123.push_back(GM);
	newcar* Honda = new newcar("7788", "HONDA", "ACCORD", 2017, 27000.00, "NEW", "MUSTAFA");
	carList123.push_back(Honda);
	oldcar* Ford = new oldcar("2267", "FORD", "FUSION", 2004, 7000.00, "OLD", 85000);
	carList123.push_back(Ford);
	newcar* Tesla = new newcar("6677", "TESLA", "S", 2018, 45000.00, "NEW", "ROCKEY");
	carList123.push_back(Tesla);
	oldcar* Nissan = new oldcar("3413", "NISSAN", "ALTIMA", 2017, 5000.00, "OLD", 112000);
	carList123.push_back(Nissan);
	newcar* Audi = new newcar("9922", "AUDI", "A4", 2018, 26000.00, "NEW", "AARON");
	carList123.push_back(Audi);
	newcar* Audi2 = new newcar("9945", "AUDI", "A5", 2018, 26000.00, "NEW", "PIRATES");
	carList123.push_back(Audi2);
	oldcar* Charger = new oldcar("5535", "CHRYSLER", "CHARGER", 2013, 15000.00, "OLD", 44000.00);
	carList123.push_back(Charger);
	newcar* BMW = new newcar("9922", "BMW", "X5", 2018, 36000.00, "NEW", "ZARA");
	carList123.push_back(BMW);
	//----------------------------------------------------------------
	// Menu Option
	bool condition = true;
	while (condition)
	{
		cout << "===================================== MENU ==================================" << endl;
		cout << "*****************************************************************************" << endl;
		cout << left << "(1) Display or Load Car Catalog" << endl;
		cout << left << "(2) Search Inventory	" << endl;
		cout << left << "(3) Sell OR Lease a Car" << endl;
		cout << left << "(4) Return A Leased Car into the Inventory" << endl;
		cout << left << "(5) Add Car to The Inventory" << endl;
		cout << left << "(6) Search Car by Price Range" << endl;
		cout << left << "(7) Write Car Data into the File" << endl;
		cout << left << "(8) Read Car Data from the File" << endl;
		cout << left << "(9) Exit	" << endl;
		//------------------------------------------------------------------
		cout << "Please Choose The Menu Option You Want To Search: ";
		int option;
		bool input = false;
		while (!input)
		{
			input = true;
			cin >> option;
			if (!cin)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please Choose Correct Menu Option." << endl;
				input = false;
			}
		}
		if (option == 1)
		{
			catalog123(carList123);// will print the cetelog
			
		}
		else if (option == 2)
		{
			//Than provide a search option by make, model and category
			Search_D_Inventory(carList123);
		}

		else if (option == 3)
		{
			//sell car option
			sell_car(carList123);
		}
		else if (option == 4)//return car option
		{
			returnCar(carList123);
		}
		else if (option == 5)//add car option
		{
			addCar(carList123);
		}

		else if (option == 6)// search by price range option
		{
			show_car_within_prange(carList123);
		}
		else if (option == 7)// write Car  data into file option
		{
			print_data_into_file(carList123);
		}

		else if (option == 8)//Read car data from file option
		{
			read_data_from_file(carList123);
		}

		else if (option == 9)// Exit from the menu option
		{
			break;//will break the loop	
		}

		else // send the message if user choose wrong option
		{
			cout << "Please Choose Right Option!" << endl;
		}

	}
	//************ End of menu option******************//

	system("PAUSE");
	return 0;
}
//end of main function
#endif

//======Functions Definations=======
//Function defination that add a car in vector list

void addCar(vector<car*> &carlist1)
{
	try //try block for exception handling
	{

	//string ch;
	//getline(cin, ch);
	string vin, make, model, cate_gory; 
	int year; float price; 
	int mileage; 
	string warrenty;
		cout << "Enter Car VIN: ";
		cin >> vin;
		for (int i = 0; i < carlist1.size(); i++)
		{
			if (vin == carlist1[i]->get_VIN())
				throw exception(" Car Already exist in the Inventory"); // throwing exception if car
															            // already exixt in the inventory
		}

		cout << "Enter Car make: ";
		
		cin>>make;
		cout << "Enter Car model: ";
		cin>> model;
		cout << "Enter Car year: ";
		cin >> year;
		cout << "Enter Car price: ";
		cin >> price;
		cout << "Enter Car Category (Either NEW or OLD): ";
		cin >> cate_gory;
		convert_string(cate_gory);

		if (cate_gory =="NEW" )	
		{	
			cout << "Enter Car Warrenty:";
			cin >> warrenty;
			newcar* New_Car = new newcar(vin, make, model, year, price, cate_gory, warrenty);
			carlist1.push_back(New_Car);
			cout << "NEW Car added Into the Inventory" << endl;
		}
		else if
			(cate_gory == "OLD")
		{
			{
				cout << "Enter Car mileage:";
				cin >> mileage;
				oldcar* old_car = new oldcar(vin, make, model, year, price, cate_gory, mileage);
				carlist1.push_back(old_car);
				cout << "Old Car added Into the Inventory" << endl;
			}
		}
		else
			throw(5);
		
	}
	catch (int x)//catch block 
	{
		cout << "Exception found:Car Category must be new or old" << endl;
	}
	catch (string abc) //catch block 
	{
		cout<<"Exception Found:"<<abc << endl;	
	}
	catch (...)
	{
		cout << "Car already exists in The Inventory" << endl;
	}
} 

// **Function Defination that print out car catelog**

void catalog123(vector<car*>&carlist2)
{
	cout << fixed << setprecision(2)<<endl;
	cout << "                                             ==**Car Catelog**=="  << endl<<endl;
	cout << setw(15) << "==VIN==" << setw(15) << setw(15) << "==Make==" << setw(25) << "==Model=="<< setw(15) << "==Year==" 
		<< setw(15) << "==Price==" << setw(15) << "==Category==" << setw(15)<<"==Mileage=="<<setw(15)<<"==Warrenty Provider=="<<endl << endl;

for (int i = 0; i < carlist2.size(); i++)
	{
	carlist2[i]->print(); 	
	}
} 

// Function Defination that Search The specific Car from the Inventor
void Search_D_Inventory(vector<car*>&carlist3)
{
	cout << "******************************************" << endl;
	cout << "(1)For Searching by Make of Car enter 1" << endl;
	cout << "(2)For Searching by MODEL of Car enter 2  " << endl;
	cout << "(3)For Searching by Category of Car enter 3 " << endl;
	cout << "*******************************************" << endl;
	bool pt = false;
	int inpt;
	while (!pt)
	{
		pt = true;
		cin >> inpt;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please Choose correct option between 1 to 3: You entered ";
			pt = false;
		}
	}

	try{         //try block 

		if (inpt == 1)
		{
			bool found = false;
			string c_Make;
			cout << "Please Enter Car Make to search: ";
			cin >> c_Make;
			convert_string(c_Make);
			for (int i = 0; i < carlist3.size(); i++)
			{
				if (c_Make == carlist3[i]->get_make())
				{
					cout << setw(15) << "==VIN==" << setw(15) << setw(15) << "==Make==" << setw(25) << "==Model=="<< setw(15) << "==Year==" 
						<< setw(15) << "==Price==" << setw(15) << "==Category==" << setw(15) << "==Mileage=="<< setw(15) << "==Warrenty Provider==" 
						<< endl << endl;

					carlist3[i]->print();
					found = true;
				}
			}
			if (found == false)
				cout << "Sorry! The Make you entered doesn't match with any Car in the Inventory." << endl;
		}
		else if (inpt == 2)
		{
			bool found = false;
			string c_MODEL;
			cout << "Enter Car Model to Search:";
			cin >> c_MODEL;
			convert_string(c_MODEL);
			for (int i = 0; i < carlist3.size(); i++)
			{
				if (c_MODEL == carlist3[i]->get_model())
				{
					cout << setw(15) << "==VIN==" << setw(15) << setw(15) << "==Make==" << setw(25) << "==Model=="<< setw(15) << "==Year==" 
						<< setw(15) << "==Price==" << setw(15) << "==Category==" << setw(15)<< "==Mileage==" << setw(15) << "==Warrenty Provider==" 
						<< endl << endl;

					carlist3[i]->print();
					found = true;
				}
			}
			if (found == false)
				cout << "Sorry! The Model you entered doesn't match with any Car in the Inventory." << endl;
		}
		else if (inpt == 3)
		{
			bool found = true;
			string c_CAT;
			cout << "Enter Car Category to search either NEW or OLD:";
			cin >> c_CAT;
			convert_string(c_CAT);
			if (c_CAT != "NEW" && c_CAT != "OLD")
				throw 99;

			cout << setw(15) << "==VIN==" << setw(15) << setw(15) << "==Make==" << setw(25) << "==Model=="
				<< setw(15) << "==Year==" << setw(15) << "==Price==" << setw(15) << "==Category==" << setw(15)
				<< "==Mileage==" << setw(15) << "==Warrenty Provider==" << endl << endl;
			for (int i = 0; i < carlist3.size(); i++)
			{
				if (c_CAT == carlist3[i]->get_catagory())
				{
					carlist3[i]->print();
					found = true;
				}
			}

			if (found == false)
				cout << "Sorry! The Category you entered doesn't match with any Car in the Inventory." << endl;
		}
		else
		{
			cout << "The Search Option you Entered is not Correct." << endl;
		}
	}
	catch (int t)
	{
		cout << "Exception found: Category must be NEW or OLD" << endl;
	}
	}

//***----------------------------------------***

// Function Defination that sell car 
void sell_car(vector<car*>&carlist4)
{
	bool s = false;
	cout << "For Sell the car please enter: 1 " << endl;
	cout << "For Lease car please enter: 2 " << endl;
	int sl;
	int option;
	bool sellinput = false;
	while (!sellinput)
	{
		sellinput = true;
		cin >> sl;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please Choose Correct Option." << endl;
			sellinput = false;
		}

		if (sl == 1)
		{
			cout << "Please Enter the VIN number you Want to Sell:";
		}
		else if (sl == 2)
		{
			cout << "Please enter VIN number you want to lease:" << endl;
		}
		else if (sl < 1 || sl>1)
		{
			cout << "You entered wrong  option" << endl;
			sellinput = false;
		}
	}
	string sell_vin;
	cin >> sell_vin;
	for (int i = 0; i < carlist4.size(); i++)
	{
		if (sell_vin == carlist4[i]->get_VIN())
		{ 
			carlist4.erase(carlist4.begin() + i);
			s = true;
		}
	}
	if (sl==1 && s==true)
	{
		cout << "Car sold successfully" << endl;

	}
	else if (sl == 2 && s == true)
	{
		cout << "Car Lease successfully" << endl;
	}
	else
		cout << "Sorry! The Car VIN Number you entered Not found" << endl;
}

// Function Defination that a Return a car 
void returnCar(vector<car*>&carlist5)
{
	try{
		cout << "Enter the Return Car information To Add in the inventory:" << endl;
		string vin, make, model, cate_gory; int year; float price; int mileage; string warrenty;
		cout << "Enter Car VIN: ";
		cin >> vin;
		for (int i = 0; i < carlist5.size(); i++)
		{
			if (vin == carlist5[i]->get_VIN())
				throw exception(" Car Already exist in the Inventory"); // throwing exception if car
			// already exixt in the inventory
		}

		cout << "Enter Car make: ";
		cin >> make;
		cout << "Enter Car model: ";
		cin >> model;
		cout << "Enter Car year: ";
		cin >> year;
		cout << "Enter Car price: ";
		cin >> price;
		cout << "Enter Return Car Category NEW or OLD: ";
		cin >> cate_gory;
		//
		convert_string(cate_gory);

		if (cate_gory == "NEW")
		{
			cout << "Enter Car Warrenty:";
			cin >> warrenty;
			newcar* New_Car = new newcar(vin, make, model, year, price, cate_gory, warrenty);
			carlist5.push_back(New_Car);
			cout << "NEW Car Returned Into the Inventory" << endl;
		}
		else if	(cate_gory == "OLD")
		{
				cout << "Enter Car mileage:";
				cin >> mileage;
				oldcar* old_car = new oldcar(vin, make, model, year, price, cate_gory, mileage);
				carlist5.push_back(old_car);
				cout << "Old Car Returned Into the Inventory" << endl;	
		}

		else 
			throw(66);
	}
	
	catch (int x)//catch block 
	{
		cout << "Exception found:Car Category must be new or old" << endl;
	}
	catch (string abc) //catch block 
	{
		cout << "Exception Found:" << abc << endl;
	}
	catch (...)
	{
		cout << "Car already exists in The Inventory" << endl;
	}

}

// extra credit 

void show_car_within_prange(vector <car*>&carlist6)
{
	bool price = false;
	float upper_price;
	float lower_price;
	cout << "Please Enter the Car Price Range." << endl;
	cout << "Please Enter lower price:";
	cin >> lower_price;
	cout << "Please Enter the upper price:";
	cin >> upper_price;
	cout << endl;
	cout << left << fixed << setprecision(2)  ;
	cout << "                                  ==*Car Catelog*==" << endl << endl;
	cout << setw(12) << "==VIN==" << setw(12) << setw(12) << "==Make==" << setw(18) << "==Model=="
		<< setw(12) << "==Year==" << setw(12) << "==Price==" << setw(12) << "==Category==" << setw(12) << "==Mileage==" << setw(12) << "==Warrenty Provider==" << endl << endl;
	for (int i = 0; i < carlist6.size(); i++)
	{
		if (carlist6[i]->get_price() >= lower_price && carlist6[i]->get_price() <= upper_price)
		{
			carlist6[i]->print();
			price = true;
		}
		
	}

	if (price == false)
	{
		cout << "Sorry! No car found within this price range." << endl;
	}
}

// Extra Credit
//Function Definationm write the Car data into the file
void print_data_into_file(vector<car*>  &carlist7)
{
	ofstream outData;
	outData.open("car.dat");
	cout << endl << "Sending Data Into File...........  "<<endl;
	for (int i = 0; i < carlist7.size(); i++)
	{
		outData << carlist7[i]->get_VIN() << " ";
		outData << carlist7[i]->get_make() << " ";
		outData << carlist7[i]->get_model() << " ";
		outData << carlist7[i]->get_catagory() << " ";
		outData << carlist7[i]->get_year() << " ";
		outData << carlist7[i]->get_price() << " " << endl;
	}
	outData.close();
	cout << "........got it! Data Successfully sent to the file" << endl<<endl;
}
//Function Defination that read data from the file
void read_data_from_file(vector<car*> &carlist8)
{
	string vin1, make1, model1; int year1; float price1; string category1;
	ifstream inData;
	inData.open("Car_data.dat");
	if (!inData)
	{
		cout << "Failed to open file" << endl;
	}
	else if (inData)
	{
		int count = 0;
		cout << "Printing Car Data From the file" << endl<<endl;
		while (!inData.eof())
		{ 
			count++;
			cout << "Car:#" <<count<< endl;
			inData >> vin1;  cout << "Car VIN:"; cout << vin1 << endl;
			inData >> make1; cout << "Car Make:"; cout << make1 << endl;
			inData >> model1;  cout << "Car Model:"; cout << model1 << endl;
			inData >> year1; cout << "Car Year:"; cout << year1 << endl;
			inData >> price1; cout << "Car Price:"; cout << price1 << endl;
			inData >> category1;  cout << "Car Category:"; cout << category1 << endl << endl ;
		}
	}
	cout << endl << endl;
}

// function defination to make upper case string 
void convert_string(string& st)
{
	for (int i = 0; i < st.length(); i++)
	{
		st[i] = toupper(st[i]);
	}
}