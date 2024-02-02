#include<iostream>
using namespace std;
int main(){
    int num;
    int factorial= 1;

    cout<<"Enter the factorial number: ";
    cin>>num;
    

    for(int i=num; i>0; i--){
        
        factorial = factorial * i;
    }

    cout<<"Factorial value is: "<<factorial;

}