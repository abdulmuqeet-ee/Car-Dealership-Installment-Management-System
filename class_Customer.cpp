#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


class Customer {
private:
    int customerID;
    string name;
    string cnic;
    double monthlySalary;

public:
    Customer(int id, string n, string c, double salary = 0.0)
        : customerID(id), name(n), cnic(c), monthlySalary(salary) {}

    int getID() const { return customerID; }
    string getName() const { return name; }
    string getCNIC() const { return cnic; }
    double getSalary() const { return monthlySalary; }
};

