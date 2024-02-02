#include<iostream>
using namespace std;
int main(){
    // maximum number from array

    int array_size;
    cin>>array_size;
    
    int array[array_size];

    for(int i=0; i<array_size;i++){
        cout<<"Enter the array element: ";
        cin>>array[i];
    }
    int max_array = array[0];
    for (int  i = 0; i < array_size; i++)
    {
        cout<<" "<<array[i];
        if(max_array<array[i]){
            max_array = array[i];
        }
        
    }
    cout<<"Maximum array element is: "<<max_array;
    
    
}