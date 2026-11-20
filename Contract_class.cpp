#include "iostream"
#include "iomanip"
#include "string"
using namespace std;

class Contract : public Printable {
private:
    int contractID;
    Customer customer;
    Car* car;
    string planType;
    int durationMonths;
    double downPayment;
    double monthlyInstallment;
    double remainingBalance;

    void calculatePlan(int years, double downPercent = 25.0) {
        double price = car->getPrice();
        downPayment = price * (downPercent / 100.0);
        double financedAmount = price - downPayment;
        double totalMarkup = financedAmount * car->getMarkupRate() * years;
        double totalPayable = financedAmount + totalMarkup;

        durationMonths = years * 12;
        monthlyInstallment = totalPayable / durationMonths;
        remainingBalance = totalPayable;
    }

public:
    Contract(int cID, Customer cust, Car* selectedCar, int years)
        : contractID(cID), customer(cust), car(selectedCar), planType("Standard Plan") {
        calculatePlan(years, 25.0);
    }

    Contract(int cID, Customer cust, Car* selectedCar, int years, bool isCustomSalaryPlan)
        : contractID(cID), customer(cust), car(selectedCar), planType("Custom Salary-Based Plan") {
        calculatePlan(years, 25.0);
    }

    int getContractID() const { return contractID; }
    string getCustomerCNIC() const { return customer.getCNIC(); }
    double getRemainingBalance() const { return remainingBalance; }
    double getMonthlyInstallment() const { return monthlyInstallment; }

    bool isAffordable() const {
        if (planType != "Custom Salary-Based Plan" || customer.getSalary() <= 0) return true;
        return monthlyInstallment <= (customer.getSalary() * 0.40);
    }

    void payInstallment(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        remainingBalance -= amount;
        if (remainingBalance < 0) remainingBalance = 0;
        cout << "Payment of PKR " << fixed << setprecision(0) << amount
             << " recorded! Remaining Balance: PKR " << remainingBalance << endl;
    }

    void displayDetails() const override { /* Prints formatted receipt */ }
    string toFileString() const { /* Formats CSV string for file storage */ }
};
