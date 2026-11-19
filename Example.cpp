#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
class abdullah{
    private: 
    string name;
    int age;
    double income;
    public:
    void getdata() {
        cout<<"\n***Enter Information***\n";
        cout<<"\nEnter Name:\n";
        getline(cin>>ws, name);
        cout<<"\nEnter age:\n";
        cin>>age;
        cout<<"\nEnter income:\n";
        cin>>income;
    }
    void displaydata() {
        cout<<"\n***Displaying Information***\n";
        cout<<"\tName:"<< name <<"\tAge:" << age <<"\tIncome:" << income << endl;
    }
};

int main() {
    abdullah a1;
    a1.getdata();
    a1.displaydata();
    return 0;
}