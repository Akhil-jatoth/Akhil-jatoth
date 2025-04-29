#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include<windows.h>
using namespace std;

// Helper function to compare two strings case-insensitively
bool compareIgnoreCase(string a, string b) {
    SetConsoleOutputCP(CP_UTF8);
    if (a.length() != b.length()) return false;
    for (size_t i = 0; i < a.length(); i++) {
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    }
    return true;
}

// Class for Taxi
class Taxi {
public:
    int taxiID;
    string driverName;
    string vehicleNumber;
    string dropLocation;
    int driverID;
    int ETA; // Estimated time to arrival (minutes)
    float additionalCharges;
    float distance; // in km

    // Constructor
    Taxi(int id, string driver, int dID, string vehicle, string location, int eta, float charges, float dist) {
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

    // Destructor
    ~Taxi() {
        SetConsoleOutputCP(CP_UTF8);
        cout << " Taxi " << taxiID << " (" << driverName << ") has completed the service!" << endl;
    }

    void showDetails() {
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

// Class for Passenger
class Passenger {
public:
    string name;

    Passenger(string n) {
        SetConsoleOutputCP(CP_UTF8);
        name = n;
        cout << " Passenger " << name << " entered the queue." << endl;
    }

    ~Passenger() {
        SetConsoleOutputCP(CP_UTF8);
        cout << " Passenger " << name << " has been served." << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "\n*************************************************" << endl;
    cout << "🚖 Welcome to QUICK RIDE Taxi Service 🚖" << endl;
    cout << "*************************************************\n" << endl;

    cout << "📢 Passenger reached the stand.\n" << endl;

    // Stack to store last taxi selections
    stack<int> taxiHistory;
    
    // Queue to store passengers
    queue<Passenger> passengers;
    
    // Add passengers
    passengers.push(Passenger("Amit"));
    passengers.push(Passenger("Priya"));

    // Create 5 taxis
    Taxi taxis[5] = {
        Taxi(1, "John", 101, "TS12AB0000", "Airport", 30, 50, 15.2),
        Taxi(2, "Mike", 102, "TS14CD5555", "Mall", 20, 30, 7.5),
        Taxi(3, "Sara", 103, "TS16EF9999", "Hotel Grand", 25, 40, 12.3),
        Taxi(4, "David", 104, "TS18GH1166", "Train Station", 15, 20, 5.8),
        Taxi(5, "Anna", 105, "TS20IJ5588", "Downtown", 35, 60, 18.5)
    };

    cout << "\n🚖 Available Drop Locations:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "📍 " << taxis[i].dropLocation << endl;
    }

    string userDropLocation;
    cout << "\n👉 Enter your desired drop location: ";
    getline(cin >> ws, userDropLocation);

    bool foundTaxi = false;
    int selectedTaxiIndex = -1;

    // Search for taxi matching drop location
    for (int i = 0; i < 5; i++) {
        if (compareIgnoreCase(userDropLocation, taxis[i].dropLocation)) {
            foundTaxi = true;
            selectedTaxiIndex = i;
            break;
        }
    }

    if (!foundTaxi) {
        cout << "\n❌ Sorry, no taxi available for that location right now." << endl;
        cout << "🚖 Please try again later." << endl;
        return 0;
    }

    taxis[selectedTaxiIndex].showDetails();
    taxiHistory.push(selectedTaxiIndex + 1); // Save to stack

    // Cost Calculation
    float baseCostPerKm = 15; // Rs per km
    float baseFare = taxis[selectedTaxiIndex].distance * baseCostPerKm;
    float totalCost = baseFare + taxis[selectedTaxiIndex].additionalCharges;

    cout << "\n💰 Fare Breakdown:" << endl;
    cout << "Base Fare (" << taxis[selectedTaxiIndex].distance << " km × Rs." << baseCostPerKm << ") = Rs." << baseFare << endl;
    cout << "Additional Charges = Rs." << taxis[selectedTaxiIndex].additionalCharges << endl;
    cout << "---------------------------------------------" << endl;
    cout << "✅ Total Payable Amount: Rs." << totalCost << endl;

    // Payment Method
    int paymentChoice;
    cout << "\n💳 Choose your Payment Method:" << endl;
    cout << "1. Cash\n2. Card\n3. PhonePe\n4. Google Pay\n5. Paytm" << endl;
    cout << "👉 Enter your choice: ";
    cin >> paymentChoice;

    switch (paymentChoice) {
        case 1:
            cout << "\n✅ Payment successful via Cash. Thank you!" << endl;
            break;
        case 2:
            cout << "\n✅ Payment successful via Card. Thank you!" << endl;
            break;
        case 3:
            cout << "\n✅ Payment successful via PhonePe. Thank you!" << endl;
            break;
        case 4:
            cout << "\n✅ Payment successful via Google Pay. Thank you!" << endl;
            break;
        case 5:
            cout << "\n✅ Payment successful via Paytm. Thank you!" << endl;
            break;
        default:
            cout << "\n❌ Invalid payment method selected!" << endl;
            return 0;
    }

    // Passenger served
    passengers.pop();

    cout << "\n*************************************************" << endl;
    cout << "🎉 Thank you for choosing QUICK RIDE Taxi Service! 🎉" << endl;
    cout << "Have a Safe and Happy Journey! ✈️" << endl;
    cout << "*************************************************\n" << endl;

    return 0;
}
