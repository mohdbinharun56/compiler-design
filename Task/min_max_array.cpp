#include<iostream>
using namespace std;
int main(){
    // maximum number from array
    int array_size;
    int array[array_size];
    cout<<"Declare array size: ";
    cin>>array_size;
    cout<<"Enter the array element: ";
    for(int i=0; i<array_size;i++){
        cin>>array[i];
    }

    int max_array = array[0];
    for(int i=1;i<array_size;i++){
        if(max_array<array[i]){
            max_array = array[i];
        }
    }
    cout<<"Max array is: "<<max_array;

}