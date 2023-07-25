#include<iostream>
#include<string.h>
#include <conio.h> 
#include <fstream>
#include <iomanip>
#include <istream>
using namespace std;


/*
Name = Ibrahim Ahmad
Roll No = 22i-8781
Department = Software Engineering
Date 10-5-23
*/


// Classes for Entitities

// -----------------------------------------------------------------
// class for person base class for user(passenger) and admin	   -
// also person can not exist separately with help of polyorphism   -
//	----------------------------------------------------------------
class Person
{

private:
	string name;
	long long cnic; //cnic[16] ;
public:

	Person()
	{
		this->name = "";
		this->cnic = 0;
	}
	// parametrized constructor
	Person(string name_, long long cnic_)
	{
		this->name = name_;
		this->cnic = cnic_;
	}

	// getter setter
	void Set_Entity_Name(string n) { this->name = n; }
	string Get_Entity_Name() { return this->name; }

	void Set_Entity_Cnic(long long c) { this->cnic = c ; }
	long long Get_Entity_Cnic() { return this->cnic; }

	// virtual function
	virtual void Majic1() = 0;
};

// Class for Customer

// ---------------------------------------------------------------------------
// class for user(passenger) with extra attributes like age, gender passport -
//	--------------------------------------------------------------------------
class Customer : public Person
{
private:
	string customerPassword;
	int age;
	string gender;
    string passport;

public:
	// default constructors
	Customer() : Person()
	{
		this->customerPassword = " ";
		this->age = 0;
		this->gender = " ";
	}

	//parametrized constructor
	Customer(string name, long long cnic, string customerpassword, int age, string gender) : Person(name, cnic)
	{
		this->customerPassword = customerpassword;
		this->age = age;
		this->gender = gender;
	}

	// getter setter
	void Set_Customer_Password(string n) { this->customerPassword = n; }
	string Get_Customer_Password() { return this->customerPassword; }

	void Set_Customer_Age(int c) { this->age = c; }
	int Get_Customer_Age() { return this->age; }

	void Set_Customer_Gender(string n) { this->gender = n; }
	string Get_Customer_Gender() { return this->gender; }

	void Majic1() { cout << " MAJIC IS OCCOURING" << endl; }

};

// Class for Admin

// --------------------------------------------------------------
// class for admin with extra attributes like adminpassword		-
// 3 admins are already existed in system						-
// admin can add flights, delete flights, view flights			-
//	-------------------------------------------------------------
class Admin : public Person
{
private:
	string adminPassword;
public:

	// getter setter
	void Set_Admin_Password(string n) { this->adminPassword= n; }
	string Get_Admin_Password() { return this->adminPassword; }

	Admin() : Person()
	{
		this->adminPassword = " ";
	}

	//parametrized constructor
	Admin(string name, long long cnic, string adminpassword) : Person(name, cnic)
	{
		this->adminPassword = adminpassword;
	}

	void Majic1() { cout << " MAJIC IS OCCOURING" << endl; }

};

// Class for Flight

// --------------------------------------------------------------------------
// class for flight base class for Local flights and International flights  -
// also flight can not exist separately with help of polyorphism			-
//	-------------------------------------------------------------------------

class Flight
{

	string departureCity;
	string arrivalCity;
//protected:
//	Booking *bookFlight;

public:
	Flight()
	{		
		this->departureCity = "";
		this->arrivalCity = "";
//		bookFlight = new Booking;
	}
	Flight(string departure_city, string arrival_city)
	{
		this->departureCity = departure_city;
		this->arrivalCity = arrival_city;
//		bookFlight = new Booking;
	}
	void Set_Departure_City(string n) { this->departureCity = n; }
	string Get_Departure_City() { return this->departureCity; }
	void Set_Arrival_City(string n) { this->arrivalCity = n; }
	string Get_Arrival_City() { return this->arrivalCity; }
	virtual void Majic2() = 0;
};


// Class for Local Flight

// --------------------------------------------------------------
// class for Local Flight inherited from flight					-
// with extra attributes like flight hours						-
// 9 Local Flights are already existed in system				-
// --------------------------------------------------------------

class LocalFlight : public Flight
{
	float flightHours;

public:
	//constructors
	LocalFlight() :Flight()
	{
		this->flightHours = 0;
	}
	// parametrized constructor
	LocalFlight( string departure_city, string arrival_city, float flight_hours) :Flight( departure_city, arrival_city)
	{
		this->flightHours = flight_hours;
	}
	//getter setter
	void Set_Flight_Hours(float n) { this->flightHours = n; }
	float Get_Flight_Hours() { return this->flightHours; }

	void Display()
	{
		cout << "Departure City: " << this->Get_Departure_City() ;
		cout << "\t Arrival City: " << this->Get_Arrival_City() ;
		cout << "\t Flight Hours: " << this->flightHours << endl;
	}

	void BookFlights(double ticketPrice, int SeatNumber, string FlightNumber)
	{
		//this->bookFlight->Set_Ticket_Price(ticketPrice);
		//this->bookFlight->Set_Seat_Number(SeatNumber);
		//this->bookFlight->Set_Flight_Number(FlightNumber);
	}

	void Majic2() { cout << "WELCOME TO WORLD OF MAJIC " << endl; }
};


// class for International Flight

// --------------------------------------------------------------
// class for International Flight inherited from flight			-
// with extra attributes like flight hours						-
// 5 Local Flights are already existed in system				-
// --------------------------------------------------------------
class InternationalFlight : public Flight
{
	float flightHours;
public:
	InternationalFlight() :Flight()
	{
		this->flightHours = 0;
	}
	// parametrized constructor
	InternationalFlight(string departure_city, string arrival_city, float flight_hours) :Flight( departure_city, arrival_city)
	{
		this->flightHours = flight_hours;
	}

	void Display()
	{
		cout << "Departure City: " << this->Get_Departure_City() ;
		cout << "\t Arrival City: " << this->Get_Arrival_City()  ;
		cout << "\t Flight Hours: " << this->flightHours << endl;
	}


	void Set_Flight_Hours(float n) { this->flightHours = n; }
	float Get_Flight_Hours() { return this->flightHours; }
	void Majic2() { cout << "WELCOME TO WORLD OF MAJIC " << endl; }

	void BookFlights(double ticketPrice , int SeatNumber , string FlightNumber)
	{
		//this->bookFlight->Set_Ticket_Price(ticketPrice);
		//this->bookFlight->Set_Seat_Number(SeatNumber);
		//this->bookFlight->Set_Flight_Number(FlightNumber);
	}
};

//---------------------------------------------------
// Class for Booking								-
// it will be composition inside Flight class		-
//---------------------------------------------------
class Booking
{
	double TicketPrice;
	int seatNumber;
	string FlightNumber;

public:
	//constructors
	Booking()
	{
		this->TicketPrice = 0;
		this->seatNumber = 0;
		this->FlightNumber = "";
	}
	// parametrized constructor
	Booking(double ticket_price, int seat_number, string flight_number)
	{
		this->TicketPrice = ticket_price;
		this->seatNumber = seat_number;
		this->FlightNumber = flight_number;
	}
	//getter setter
	void Set_Ticket_Price(double n) { this->TicketPrice = n; }
	double Get_Ticket_Price() { return this->TicketPrice; }
	void Set_Seat_Number(int n) { this->seatNumber = n; }
	int Get_Seat_Number() { return this->seatNumber; }
	void Set_Flight_Number(string n) { this->FlightNumber = n; }
	string Get_Flight_Number() { return this->FlightNumber; }

};


//===================================================================================================
// Classes for Airports

// --------------------------------------------------------------
// class for Airports											-
// with extra attributes like number of airplanes	city 		-
// --------------------------------------------------------------
class Airports
{
	string city;
	int numberAirplanes;
	public:

	//constructors
	Airports(/*Flight schedule*/)
	{
	this->city = "";
	this->numberAirplanes = 0;
	}
	// parametrized constructor
	Airports(string city_, int numberAirplanes=0)
	{
		this->city = city_ ;
	}

	//getter setter
	void Set_Airport_City(string n) { this->city = n; }
	string Get_Airport_City() { return this->city; }
	void Set_Airport_NumberAirplanes(int n) { this->numberAirplanes = n; }
	int Get_Airport_NumberAirplanes() { return this->numberAirplanes; }
};

//

//===============================================================
// Ultimalte class of Nuces Airline Flight System
// it aggregates all of the Admis Passengers Flights
// ==============================================================
class NAFS
{
private:
	Customer* AllCustomers;
	Admin* AllAdmins;
	LocalFlight* AllLocalFlights;
	InternationalFlight* AllInternationalFlights;
public:
	NAFS(Customer C[], Admin A[], LocalFlight LC[], InternationalFlight IF[])
	{
		this->AllCustomers = C;
		this->AllAdmins = A;
		this->AllLocalFlights = LC;
		this->AllInternationalFlights = IF;
	}

	void writeToFile(string fileName) {
		ofstream file(fileName);

		if (!file) {
			cerr << "Error: Unable to create file: " << fileName << endl;
			return;
		}

		// Write the admin data to file
		file << "Admin Data:\n";
		for (int i = 0; i < 3; i++) {
			file << "Admin " << i + 1 << ":\n";
			file << "Admin Username: " << AllAdmins[i].Get_Entity_Name() << endl;
			file << "Admin Password: " << AllAdmins[i].Get_Admin_Password() << endl;
		}

		file << "\nCustomer Data:\n";
		for (int i = 0; i < 5; i++) {
			file << "Customer " << i + 1 << ":\n";
			file << "Name: " << AllCustomers[i].Get_Entity_Name() << endl;
			file << "CNIC: " << AllCustomers[i].Get_Entity_Cnic() << endl;
			file << "Customer Password: " << AllCustomers[i].Get_Entity_Name() << endl;
			file << "Age: " << AllCustomers[i].Get_Customer_Age() << endl;
			file << "Gender: " << AllCustomers[i].Get_Customer_Gender() << endl << endl;

		}
		file << "----------------------------------------------" << endl;

		// Write the flight data to file
		file << "\nLocal Flight Data:\n";
		for (int i = 0; i < 10; i++) {
			file << "Flight " << i + 1 << ":\n";
			file << "Departure City: " << AllLocalFlights[i].Get_Departure_City()<< endl;
			file << "Arrival City: " << AllLocalFlights[i].Get_Arrival_City() << endl;
			file << "Flight Hours: " << AllLocalFlights[i].Get_Flight_Hours() << endl << endl;
		}
		file << "----------------------------------------------" << endl;
		file << "\nInternational Flight Data:\n";
		for (int i = 0; i < 5; i++) {
			file << "Flight " << i + 1 << ":\n";
			file << "Departure City: " << AllInternationalFlights[i].Get_Departure_City() << endl;
			file << "Arrival City: " << AllInternationalFlights[i].Get_Arrival_City() << endl;
			file << "Flight Hours: " << AllInternationalFlights[i].Get_Flight_Hours() << endl << endl;
		}

		file.close();
		cout << "Data written to file: " << fileName << endl;
	}
		
};



int main()
{

	// ADMINS ALREADY EXISITING


	// variable for existing staffand flights for initialization of system and string in array

	int adminsize = 3;
	int customersize = 5;
	int localflightsize = 10;
	int internationalflightsize = 4;

	Admin* AdminsArray = new Admin[adminsize];
	Customer* CustomersArray = new Customer[customersize];
	LocalFlight* LocalFlightsArray = new LocalFlight[localflightsize];
	InternationalFlight* InternationalFlightsArray = new InternationalFlight[internationalflightsize];

	//===============================================================

	// admins creation ( name cnic password)
	Admin employee1("Shahbaz", 611011/*2343228765*/, "12345abcd");
	Admin employee2("Zubair", 612011/*2343338765*/, "1234abcd");
	Admin employee3("Romaisa", 613011/*2343448765*/, "1234abcd");

	// storing admins in array
	AdminsArray[0] = employee1;
	AdminsArray[1] = employee2;
	AdminsArray[2] = employee3;

	// customer creation ( name cnic password age gender)
	Customer c1("Hadia", 614011, "xyz987", 35, "female");
	Customer c2("John", 615011, "xyz789", 25, "male");
	Customer c3("Sarah", 616011, "zyx987", 45, "female");
	Customer c4("David", 617011, "abc123", 30, "male");
	Customer c5("Emily", 618011, "klm321", 28, "female");

	// storing customers in array
	CustomersArray[0] = c1;
	CustomersArray[1] = c2;
	CustomersArray[2] = c3;
	CustomersArray[3] = c4;
	CustomersArray[4] = c5;

	// Local flights
	LocalFlight lf1("South Lahore", "North Islamabad", 2);
	LocalFlight lf2("North Lahore", "South Karachi", 1);
	LocalFlight lf3("South Islamabad", "North Lahore", 2.5);
	LocalFlight lf4("North Islamabad", "South Islamabad", 1.5);
	LocalFlight lf5("South Karachi", "North Karachi", 1);
	LocalFlight lf6("North Karachi", "South Lahore", 1.5);
	LocalFlight lf7("South Peshawar", "North Peshawar", 2.5);
	LocalFlight lf8("North Peshawar", "South Quetta", 1);
	LocalFlight lf9("South Quetta", "North Quetta", 2);
	LocalFlight lf10("North Quetta", "South Peshawar", 1.5);

	// storing local flights in array
	LocalFlightsArray[0] = lf1;
	LocalFlightsArray[1] = lf2;
	LocalFlightsArray[2] = lf3;
	LocalFlightsArray[3] = lf4;
	LocalFlightsArray[4] = lf5;
	LocalFlightsArray[5] = lf6;
	LocalFlightsArray[6] = lf7;
	LocalFlightsArray[7] = lf8;
	LocalFlightsArray[8] = lf9;
	LocalFlightsArray[9] = lf10;


	// International flights
	InternationalFlight if1("North Lahore", "Dubai", 4.5);
	InternationalFlight if2("South Islamabad", "London", 8);
	InternationalFlight if3("South Karachi", "New York", 15);
	InternationalFlight if4("North Peshawar", "Beijing", 6);

	// storing international flights in array
	InternationalFlightsArray[0] = if1;
	InternationalFlightsArray[1] = if2;
	InternationalFlightsArray[2] = if3;
	InternationalFlightsArray[3] = if4;

	// creating object of NAFS
	// Storing all of our data in NAFS
	NAFS nafs1(CustomersArray, AdminsArray, LocalFlightsArray, InternationalFlightsArray);

	//fstream NAFS_Big_Data ;
	//nafs1.writeToFile("NAFS_Big_Data");

	cout << "************************************************************************" << endl;
	cout << "------------------------------------------------------------------------" << endl << endl;
	cout << "===========  WELCOME TO NUCES AIRLINE FLIGHT SYSTEM  ===================" << endl << endl;
	cout << "------------------------------------------------------------------------" << endl << endl;
	cout << "************************************************************************" << endl << endl;

	while (true)
	{
		int firstOption;



		cout << "\t \t  MAIN MENU " << endl << endl;
		cout << "1).  \" Login as Admin \" " << "\t \t 2). \" Login as Passenger \" " << endl;
		cout << "3).  \" Sign up as User \" " << "\t \t 4). \" View Flights \" " << endl;
		cout << "5).  \" View About Us \" " << "\t \t \t 6). \" Exit \" " << endl << endl;
		cin >> firstOption;

		switch (firstOption)
		{

		case 1:
		{
			// in admin selected option using variable related to admin
			string adminname, adminpassword;
			bool valid_credentials = false;

			// LOOP running until valid credentials are entered
			while (!valid_credentials)
			{

				cout << "ENTER YOUR USER NAME" << endl;
				cin >> adminname;

				cout << "ENTER YOUR PASSWORD" << endl;

				char AdminPasswordValidation;

				while (true) {
					AdminPasswordValidation = _getch(); // Get the next character from the console input stream

					if (AdminPasswordValidation == '\n' || AdminPasswordValidation == '\r') {
						break;
					}
					else if (AdminPasswordValidation == '\b' && !adminpassword.empty()) {
						adminpassword.pop_back();
						cout << "\b \b";
					}
					else if (isprint(AdminPasswordValidation)) {
						adminpassword.push_back(AdminPasswordValidation);
						cout << '*';
					}
				}

				for (int i = 0; i < adminsize; i++)
				{
					if (adminname == AdminsArray[i].Get_Entity_Name())
					{
						if (adminpassword == AdminsArray[i].Get_Admin_Password())
						{
							cout << "Welcome :" << adminname << endl;
							valid_credentials = true;
						}
						else
						{
							cout << "Invalid Credentials" << endl;
							break;
						}
					}

				}
			}// while loop ending for credentials

			while (true)
			{
				int option1;
				cout << "WHAT YOU WANT TO DO as admin" << endl;
				cout << "1. Add Flight" << endl;
				cout << "2. View Flights" << endl;
				cout << "3. Exit " << endl;
				cin >> option1;

				switch (option1)
				{

				case 1:
				{

					int adminflights;
					cout << " press 1 for local flight and 2 for international flight" << endl;
					cin >> adminflights;

					// amin making local flights
					if (adminflights == 1)
					{
						string departurecity, arrivalcity;
						float  flighthours;
						cout << "Enter Departure City" << endl;
						cin >> departurecity;
						cout << "Enter Arrival City" << endl;
						cin >> arrivalcity;
						cout << "Enter Flight Hours" << endl;
						cin >> flighthours;
						LocalFlight lf10(departurecity, arrivalcity, flighthours);
						LocalFlightsArray[localflightsize] = lf10;
						localflightsize++;
						break;
					}

					// admin making international flights
					if (adminflights == 2)
					{

						string departurecity, arrivalcity;
						float  flighthours;

						cout << "Enter Departure City" << endl;
						cin >> departurecity;

						cout << "Enter Arrival City" << endl;
						cin >> arrivalcity;

						cout << "Enter Flight Hours" << endl;
						cin >> flighthours;

						// creating object of international flight and storing it in array

						InternationalFlight if5(departurecity, arrivalcity, flighthours);
						InternationalFlightsArray[internationalflightsize] = if5;
						internationalflightsize++;

						break;
					}
					break;
				}
				case 2:
				{
					cout << endl << endl;
					cout << "*******************************************" << endl;
					cout << "         CURRENT LOCAL FLIGHTS ARE        *" << endl;
					cout << "*******************************************" << endl << endl;

					for (int i = 0; i < localflightsize; i++)
					{
						LocalFlightsArray[i].Display();
					}

					cout << "***************************************************" << endl;
					cout << "         CURRENT INTERNATIONAL FLIGHTS ARE        *" << endl;
					cout << "***************************************************" << endl << endl;

					for (int i = 0; i < internationalflightsize; i++)
					{
						InternationalFlightsArray[i].Display();
					}

					break;
				}
				case 3:
				{
					cout << "*******************************************" << endl;
					cout << "-------------------------------------------" << endl;
					cout << "-      THANK YOU FOR USING OUR SYSTEM     -" << endl;
					cout << "-------------------------------------------" << endl;
					cout << "*******************************************" << endl << endl;

					return 0;
					break;
				}
				default:
				{
					cout << "------------------------" << endl;
					cout << "     Invalid Option     " << endl;
					cout << "------------------------" << endl;
					break;
				}

				getchar();

				}// switch edning here

			}// while loop ending here

		}// case 1 ADMIN  ending here

// -----------------------------------------------------------------

		case 2:
		{
			// in user selected option using variable related to user
			string username, userpassword;
			bool valid_credentials = false;

			while (!valid_credentials)
			{
				cout << "ENTER YOUR USER NAME" << endl;
				cin >> username;
				cout << "ENTER YOUR PASSWORD" << endl;
				//cin >> userpassword;
				char UserPasswordValidation;
				while (true) {
					UserPasswordValidation = _getch(); // Get the next character from the console input stream

					if (UserPasswordValidation == '\r' || UserPasswordValidation == '\n') {
						break;
					}
					else if (UserPasswordValidation == '\b' && !userpassword.empty()) {
						userpassword.pop_back();
						cout << "\b \b";
					}
					else if (isprint(UserPasswordValidation)) {
						userpassword.push_back(UserPasswordValidation);
						cout << '*';
					}
				}

				// validating the user credentials
				for (int i = 0; i < customersize; i++)
				{
					if (username == CustomersArray[i].Get_Entity_Name())
					{
						if (userpassword == CustomersArray[i].Get_Customer_Password())
						{
							cout << "Welcome :" << username << endl;
							valid_credentials = true;
						}
						else
						{
							cout << "Invalid Credentials" << endl;
						}
					}
				}

			}
			while (true)
			{
				int optionUser;
				cout << "Select an Option" << endl;
				cout << "1. View Flights" << endl;
				cout << "2. Book a Flight" << endl;
				cout << "3. Change Password" << endl;
				cout << "4. Exit" << endl;
				cin >> optionUser;

				switch (optionUser)
				{

				case 1:
				{
					cout << endl << endl;
					cout << "*******************************************" << endl;
					cout << "         CURRENT LOCAL FLIGHTS ARE        *" << endl;
					cout << "*******************************************" << endl << endl;

					for (int i = 0; i < localflightsize; i++)
					{
						LocalFlightsArray[i].Display();
					}

					cout << "***************************************************" << endl;
					cout << "         CURRENT INTERNATIONAL FLIGHTS ARE        *" << endl;
					cout << "***************************************************" << endl << endl;

					for (int i = 0; i < internationalflightsize; i++)
					{
						InternationalFlightsArray[i].Display();
					}

					break;
				}
				case 2:
				{
					// Pessenger book flight 

					int flightid;
					cout << "*******************************************" << endl;
					cout << "         CURRENT LOCAL FLIGHTS ARE        *" << endl;
					cout << "*******************************************" << endl << endl;
					for (int i = 0; i < localflightsize; i++)
					{
						cout << "\t " << i + 1; LocalFlightsArray[i].Display();
					}

					cout << "***************************************************" << endl;
					cout << "         CURRENT INTERNATIONAL FLIGHTS ARE        *" << endl;
					cout << "***************************************************" << endl << endl;

					for (int i = 0; i < internationalflightsize; i++)
					{
						cout << "\t " << i + 1;	 InternationalFlightsArray[i].Display();
					}

					cout << "Enter Flight ID " << endl;
					cin >> flightid;
					cout << " You have successfully booked your flight" << endl;
					break;
				}
				case 3:
				{
					// passemger change password

					string newPassword, reEnteredPassword;
					cout << "Enter New Password" << endl;
					cin >> newPassword;
					cout << "Re-Enter New Password" << endl;
					cin >> reEnteredPassword;
					if (newPassword == reEnteredPassword)
					{
						for (int i = 0; i < customersize; i++)
						{
							if (username == CustomersArray[i].Get_Entity_Name())
							{
								CustomersArray[i].Set_Customer_Password(newPassword);
							}
						}
						cout << "---------------------------------" << endl;
						cout << "- Password Changed Successfully -" << endl;
						cout << "---------------------------------" << endl;
					}

					cout << " " << endl;
					break;
				}
				case 4:
				{
					// pessnger exit

					cout << "THANK YOU FOR USING OUR SYSTEM" << endl;
					return 0;
					break;
				}
				default:
				{
					cout << "Invalid Option" << endl;
					break;
				}

				getchar();

				}// switch edning here

			}// while loop ending here



			//Switch case 2 end user wala
			break;
		}

		// -----------------------------------------------------------------

		case 3:
		{
			// new passanger sign up
			string customername, customerpassword, customergender;
			long long customercnic;
			int customerage;


			cout << "------------------------------------------------------------------------" << endl << endl;
			cout << "===========  WELCOME TO NUCES AIRLINE FLIGHT SYSTEM  ===================" << endl << endl;
			cout << "------------------------------------------------------------------------" << endl << endl;

			cout << "\t ENTER YOUR First and Last Name" << endl;
			cin >> customername;

			cout << "ENTER YOUR CNIC" << endl;
			cin >> customercnic;

			cout << "ENTER YOUR PASSWORD" << endl;
			cin >> customerpassword;

			cout << "ENTER YOUR AGE" << endl;
			cin >> customerage;

			cout << "ENTER THE GENDER " << endl;
			cin >> customergender;

			Customer c1(customername, customercnic, customerpassword, customerage, customergender);
			CustomersArray[customersize] = c1;
			customersize++;


			cout << "------------------------------------------------------------------------" << endl;
			cout << " You are Successfuly become Memeber of NAFS Airline system \n ";
			cout << "\t Hurrah " << endl;
			cout << "We value Our Customers & Try to Provide Best Services \n Now You can avail 10% OFF on you firt travel with us " << endl;
			cout << " Go Back Login as User and Book You Flight ASAP \n" << endl;
			cout << "------------------------------------------------------------------------" << endl;


			break;
			// swithc case 3 signup as user ended
		}

		case 4:
		{

			cout << endl << endl;
			cout << "*******************************************" << endl;
			cout << "         CURRENT LOCAL FLIGHTS ARE        *" << endl;
			cout << "*******************************************" << endl << endl;

			for (int i = 0; i < localflightsize; i++)
			{
				LocalFlightsArray[i].Display();
			}

			cout << "***************************************************" << endl;
			cout << "         CURRENT INTERNATIONAL FLIGHTS ARE        *" << endl;
			cout << "***************************************************" << endl << endl;

			for (int i = 0; i < internationalflightsize; i++)
			{
				InternationalFlightsArray[i].Display();
			}

			cout << endl << endl;

			break;

		}
		case 5:
		{
			// about us 
			cout << "Welcome to NUCES Airline Flight System (NAFS), \n the newly established airline that is here to take you on a journey of comfort, safety, and reliability." << endl;
			cout << "We are proud to serve our passengers in five major cities of Pakistan\n , including Islamabad, Lahore, Quetta, Peshawar, and Karachi. " << endl;
			cout << "We are also proud to announce that we are the first airline in Pakistan to offer a\n\n \" 10% discount to our first-time customers.\" " << endl;
			cout << "At NAFS, we have designed our flight reservation system to cater to all your travel needs.\n With 10 airplanes in each city, we ensure that our passengers have the convenience of selecting their preferred travel time" << endl;
			cout << "We understand that during these unprecedented times of COVID - 19,\n travel restrictions are in place, and NAFS abides by international travel laws to ensure the safety of our passengers. " << endl;
			
			cout << "\n-----------------------------------------------------------" << endl;
			cout << "Thank you for choosing NUCES Airline Flight System (NAFS), and we look forward to serving you." << endl;
			cout << "-----------------------------------------------------------" << endl;

			break;
		}


		default:
		{
			cout << "Invalid Option" << endl;
			return 0;
			break;
		}
		getchar();
		}

	}// while loop ending here


	return 0;
}


