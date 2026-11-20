#include <iostream> 
#include <string>   

using namespace std;
class Car {

protected:

    int carID;
    string model;
    double basePrice;
    bool isSold;

public:

    Car(int id, string m, double price, bool sold = false) {
        carID = id;
        model = m;
        basePrice = price;
        isSold = sold;
    }

    int getID() const { return carID; }
    string getModel() const { return model; }
    double getPrice() const { return basePrice; }
    bool getStatus() const { return isSold; }

    void markSold() { isSold = true; }

    void displayDetails() const
    {
        cout << carID << "  " << getCategory() << "  " << model
            << "  " << "PKR " << basePrice;
        if (isSold == true) {
            cout << "[SOLD OUT]"; }
        else {
            cout << "[AVAILABLE]";}
        cout << endl;
    }
  
    virtual string getCategory() const = 0;
    virtual double getMarkupRate() const = 0;
};


/* HATCHBACK CATEGORY CARS */
class HatchBack : public Car {
public:

    HatchBack(int id, string m, double price, bool sold = false)
        : Car(id, m, price, sold) { }

    string getCategory() const { return "HatchBack"; }
    double getMarkupRate() const { return 0.05; } /*5% Annual Markup*/
};


/* SEDAN CATEGORY CARS */
class Sedan : public Car {
public:

    Sedan(int id, string m, double price, bool sold = false)
        : Car(id, m, price, sold) {    }

    string getCategory() const { return "Sedan"; }
    double getMarkupRate() const { return 0.10; } /*10% Annual Markup*/
};


/* SUV CATEGORY CARS */
class SUV : public Car {
public:

    SUV(int id, string m, double price, bool sold = false)
        : Car(id, m, price, sold) {    }

    string getCategory() const { return "SUV"; }
    double getMarkupRate() const { return 0.15; } /*15% Annual Markup*/
};
