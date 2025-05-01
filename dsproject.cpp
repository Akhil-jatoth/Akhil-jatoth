#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include<windows.h>
using namespace std;

bool compareIgnoreCase(string a, string b) 
{
    SetConsoleOutputCP(CP_UTF8);
    if (a.length() != b.length()) return false;
    for (size_t i = 0; i < a.length(); i++) 
    {
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    }
    return true;
}
class Taxi 
{
    public:
        int taxiID;
        string driverName;
        string vehicleNumber;
        string dropLocation;
        int driverID;
        int ETA; // (Estimated time to arrival)
        float additionalCharges;
        float distance; // in km
Taxi(int id, string driver, int dID, string vehicle, string location, int eta, float charges, float dist) 
{
        SetConsoleOutputCP(CP_UTF8);
        taxiID = id;
        driverName = driver;
        driverID = dID;
        vehicleNumber = vehicle;
        dropLocation = location;
        ETA = eta;
        additionalCharges = charges;
        distance = dist;
        cout << " Taxi " << taxiID << " (" << driverName << ") is ready at the stand!" << endl;
 }
    
    ~Taxi() 
    {
            SetConsoleOutputCP(CP_UTF8);
            cout << " Taxi " << taxiID << " (" << driverName << ") has completed the service!" << endl;
    }
    void showDetails() 
    {
            SetConsoleOutputCP(CP_UTF8);
            cout << "\n---------------------------------------------" << endl;
            cout << " Taxi ID: " << taxiID << endl;
            cout << "‍✈️ Driver Name: " << driverName << endl;
            cout << "🆔 Driver ID: " << driverID << endl;
            cout << "🚗 Vehicle Number: " << vehicleNumber << endl;
            cout << "📍 Drop Location: " << dropLocation << endl;
            cout << "⏳ ETA: " << ETA << " minutes" << endl;
            cout << "🚣️ Trip Distance: " << distance << " km" << endl;
            cout << "➕ Additional Charges: Rs." << additionalCharges << endl;
            cout << "---------------------------------------------" << endl;
        }
    };
    class Passenger 
   {
    public:
        string name;
    
        Passenger(string n) 
       {
            SetConsoleOutputCP(CP_UTF8);
            name = n;
            cout << " Passenger " << name << " entered the stand." << endl;
        }
    
        ~Passenger() 
       {
            SetConsoleOutputCP(CP_UTF8);
            cout << " Passenger " << name << " has been served." << endl;
        }
    };
