#include <iostream>
using namespace std;
int main(){
    string firstName;
    string lastName;
    
    cout<<"Enter Your First Name: ";
    cin>>firstName;
    
    cout<<"Enter Your Last Name: ";
    cin>>lastName;

    string fullName = firstName + " " + lastName;
    cout<<"Your Full Name: "<<fullName;
    return 0;

}