// ParkingTicket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//ParkedCar Class
class ParkedCar
{
private:
    string make; // the car's make
    string model; // the car's model
    string color; //the car's color
    string licenseNum; //the car's license number 
    int numMinPark;    // the number of minutes car is parked

public:
    ParkedCar();    // Default Constructor
    //ParkedCar(string m, string mo, string c, string li, int min);
    ParkedCar(string, string, string,string, int); //Constructor with 4 arguments

    void setMake(string);
    void setModel(string);
    void setColor(string);
    void setLicenseNumber(string);
    void setNumMinPark(int);

    string getMake() const;
    string getModel() const;
    string getColor() const;
    string getLicenseNumber() const;
    int getNumMinPark() const;
};

//**************************************************
// The Constructor initialize parameters to default value              *
//*******************************************************
ParkedCar::ParkedCar() {
    make = " ";
    model = " ";
    color = " ";
    licenseNum = " ";
    numMinPark = 0;
}

//*******************************************************
// The Constructor initialize parameters to default value              *
//*******************************************************

ParkedCar::ParkedCar(string m, string mo, string c, string li, int min)
{
    //Assigning values to make, model,color, license number, and number of minutes car parked
    make = m;
    model = m;
    color = c;
    licenseNum = li;
    numMinPark = min;
}
 
//**************************************************
// setMake assigns a value make member.             *
//**************************************************

void ParkedCar::setMake(string m)
{
    make = m;
}


//**************************************************
// setMake assigns a value model member.             *
//**************************************************

void ParkedCar::setModel(string mo)
{
    model = mo;
}


//**************************************************
// setMake assigns a value color member.             *
//**************************************************

  void ParkedCar::setColor(string c)
  {
      color = c;
  }


  //**************************************************
  // setMake assigns a value license number member.             *
  //**************************************************
void ParkedCar::setLicenseNumber(string li)
{
    licenseNum = li;
}



//**************************************************
// setMake assigns a value make member.             *
//**************************************************
void ParkedCar::setNumMinPark(int min)
{
    numMinPark = min;
}


//**************************************************
// getMake returns the value in the make member.             *
//**************************************************

string ParkedCar::getMake() const
{
    return make;
}

//**************************************************
// getModel returns the value in the model member.             *
//**************************************************

string ParkedCar::getModel() const
{
    return model;
}
  
//**************************************************
// getColor returns the value in the color member.             *
//**************************************************
string ParkedCar::getColor() const
{
    return color;
}
//**************************************************
// getLicenseNumber returns the value in the license number member.             *
//**************************************************

string ParkedCar::getLicenseNumber() const
{
    return licenseNum;
}

//**************************************************
// getminCarParked returns the value in the make member.             *
//****************************************************

int ParkedCar::getNumMinPark() const
{
    return numMinPark;
}

//ParkingMeter Class

class ParkingMeter
{
private:
    int minParkTimePurch;
public:
    ParkingMeter(); //Default constructor
    ParkingMeter(int); // Constructor with one parameter

    //
    void setMinPurch(int);

    //
    int getMinPurch() const;

};

//**************************************************
// The Constructor initialize parameters to default value              *
//*******************************************************

ParkingMeter::ParkingMeter()
{
    minParkTimePurch = 0;
}
//**************************************************
// The Constructor initialize parameters to default value              *
//*******************************************************

ParkingMeter::ParkingMeter(int min) 
{
    minParkTimePurch = min;

}
//**************************************************
// setMinPurch assigns a value minParkTimePurch member.             *
//**************************************************

void ParkingMeter::setMinPurch(int minPur)
{
    minParkTimePurch = minPur;
}

//***********************************************************
// getMinPurch return the value in the minParkTimPurch member.             *
//**********************************************************

int ParkingMeter::getMinPurch() const
{
    return minParkTimePurch;
}

// PoliceOfficer class
class PoliceOfficer
{
private:
    string name;
    string badgeNumber;
public:
    PoliceOfficer(); //Default Constructor
    PoliceOfficer(string, string); //Constructor with 2 arguments

    void setName(string );
    string getName() const;

    void setBadgeNumber(string );
    string getBadgeNumber() const;

    bool ticketValidity(ParkedCar c, ParkingMeter meter);

    double issueTicket(ParkedCar v, ParkingMeter met);




};

//**************************************************
// The Constructor initialize parameters to default value              *
//*******************************************************

PoliceOfficer::PoliceOfficer()
{
    name = " ";
    badgeNumber = " ";
}
//**************************************************
// The Constructor initialize 2 parameters              *
//*******************************************************

PoliceOfficer::PoliceOfficer(string n, string ba)
{
    name = n;
    badgeNumber = ba;
}



//**************************************************
// setName assigns a value name member.             *
//**************************************************
void PoliceOfficer::setName(string n)
{
    name = n;
}
//**************************************************
// setMBadgeNumber assigns a value badgeNumber member.             *
//**************************************************

void PoliceOfficer::setBadgeNumber(string badge)
{
    badgeNumber = badge;
}

//**************************************************
// getName returns a value name member.             *
//**************************************************
string PoliceOfficer::getName() const
{
    return name;
}

//**************************************************
// getBadgeNumber returns a value badge member.             *
//**************************************************
string PoliceOfficer::getBadgeNumber() const
{
    return badgeNumber;
}


//**********************************************************************
// bool ticketValidity true or false whether the car's time has expired.             *
//**********************************************************************

bool PoliceOfficer::ticketValidity(ParkedCar c, ParkingMeter meter)
{
    if (c.getNumMinPark() > meter.getMinPurch())
    {
        
        return true;
    }
    else
    {
        
        return false;
    }

}


//*******************************************************************************
// double issueTicket calculate the fine and return it to the client          *
//********************************************************************************

double PoliceOfficer::issueTicket(ParkedCar v, ParkingMeter met)
{
    double fine = 0.0; //Default value
    int remainMinutes = v.getNumMinPark() - met.getMinPurch();

    if (ticketValidity(v, met) == true)
    {
        fine = 25.0;
        if (remainMinutes <= 60)
        {
            
            fine += 10;  //Additional File
        }
        else
        {
            fine = 25.0 + (10.0 * (remainMinutes / 60));
        }
    }
    return fine;
 }

//ParkingTicket
class ParkingTicket
{
private:
    ParkedCar c;
    PoliceOfficer o;
    ParkingMeter m;
    
public:
    ParkingTicket(); //Default constructor;
    ParkingTicket(ParkedCar, PoliceOfficer, ParkingMeter); //Constructor with 2 object

    /*void setFine(double);
    double getFine();*/

    void reportIllegalCar(ParkedCar, PoliceOfficer,ParkingMeter);

    //void reportOfficerInfo(ParkedCar,PoliceOfficer,ParkingMeter);
};

//**************************************************
// The Constructor initialize Default            *
//*******************************************************
ParkingTicket::ParkingTicket()
{

}

//**************************************************
// The Constructor initialize 2 parameters              *
//*******************************************************

ParkingTicket::ParkingTicket(ParkedCar car, PoliceOfficer cop, ParkingMeter met)
{
    c = car;

    o = cop;

    m = met;
}
//**************************************************
// setFine assigns a value fine member.             *
//**************************************************

//void ParkingTicket::setFine(double f)
//{
//    fine = f;
//}

//**************************************************
// getFine returns a value fine member.             *
//**************************************************
//double ParkingTicket::getFine()
//{
//    return fine;
//}

//*******************************************************************************
// void ReportIllegalCar reports the make, model, color, and license number of the  
// illegal parked car            *
//********************************************************************************

void ParkingTicket::reportIllegalCar(ParkedCar c, PoliceOfficer off, ParkingMeter met)
{
    if(off.ticketValidity(c,met)== true)
    {
        cout << "\nThis car has been illegally parked" << endl;
        cout << "\nPolice Officer Information: \n";
        cout << "       Name: " << off.getName() << endl;
        cout << "       Badge Number: " << off.getBadgeNumber() << endl;

        cout << "\nCar Information: \n";
        cout << "        Make: " << c.getMake() << endl;
        cout << "        Model: " << c.getModel() << endl;
        cout << "        Color: " << c.getColor() << endl;
        cout << "        License: " << c.getLicenseNumber() << endl;
        cout << "        Minutes: " << c.getNumMinPark() << endl;


        cout << "\nTicket Information: \n";
        cout << "          Minutes in violation: " << c.getNumMinPark()-met.getMinPurch() << endl;
        cout << "          Fine: $ " << off.issueTicket(c,met) << endl;

    }
    else
    {
        cout << "No violation, ticket is valid!!";
    }
}

//***************************************************************
// void ReportOfficerInfo reports the name and badge number   
//  of the police officer issuing the ticket                    *
//***************************************************************

//void ParkingTicket::reportOfficerInfo(ParkedCar,PoliceOfficer off,ParkingMeter met)
//{
//    if (off.ticketValidity(c, met) == true)
//    {
//        cout << "Police Officer Information: \n";
//        cout << "       Name: " << off.getName() << endl;
//        cout << "       Badge Number: " << off.getBadgeNumber() << endl;
//       
//
//    }
//
//}




int main()
{
    cout << "Hello! You are able to enter in car information, how" << endl;
    cout << "much was purchased on the parking meter and an officer's" << endl;
    cout << "information to simulate a parking ticket." << endl;

    /*ParkedCar vehicle;
    ParkingMeter meter;
    PoliceOfficer officer*/;

    char again; // Loop again? Y or N

    ParkingTicket ticket;  // create ParkingTicket object called Ticket

    string make, model, color, license, name, badge;  //Variable

    int minParked, minPurch;   //Variable to store mumber of minutes the car was parked and number of minutes purchase

    do {
        // Prompting user to enter car info and Police officer info and minutes parked and purchased
        cout << "Enter car make: ";
        cin >> make;
        //vehicle.setMake(make);

        cout << "Enter car model: ";
        cin >> model;
        //vehicle.setModel(model);

        cout << "Enter car color: ";
        cin >> color;
        // vehicle.setColor(color);

        cout << "Enter car license number: ";
        cin >> license;
        //vehicle.setLicenseNumber(license);

        cout << "Enter number of minutes parked: ";
        cin >> minParked;
        //vehicle.setNumMinPark(minParked);

        cout << "Enter number of minutes purchased: ";
        cin >> minPurch;
        //meter.setMinPurch(minPurch);

        cout << "Enter officer name: ";
        cin.get();
        getline(cin, name);
        //cin>> name;
        //officer.setName(name);

        cout << "Enter badge number: ";
        cin >> badge;
        //officer.setBadgeNumber(badge);

        ParkedCar vehicle(make, model, color, license, minParked); // CREATE new Parked car objet called Vehicle

        PoliceOfficer officer(name, badge); //Create a new Police Officer object called officer

        ParkingMeter meter(minPurch);      //Create a new ParkingMeter object called meter

        ticket.reportIllegalCar(vehicle, officer, meter); // Print a new ticket


        //ticket.reportOfficerInfo(vehicle, officer, meter);
        // 
        // Does the user want to check another car?

        cout << "Do you want to check another car? (Y/N) ";
        cin >> again;

    } while ((again == 'Y') || (again == 'y'));
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
