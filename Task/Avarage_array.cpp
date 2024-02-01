#include<iostream>
using namespace std;
int main(){
    int array_size,sum=0;
    double avg;
    cout<<"Enter an array size: ";
    cin>>array_size;
    int array[array_size];
    for(int i=0; i<array_size;i++){
        cout<<"Enter the array element: ";
        cin>>array[i];
    }
    for(int i=0;i<array_size;i++){
        sum+=array[i];
    }
    avg = sum/array_size;
    cout<<"The average of the array element is: "<<avg;

}