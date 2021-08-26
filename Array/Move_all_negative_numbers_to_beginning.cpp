/*Question :- Move all negative numbers to beginning and positive to end with constant extra space
Difficulty Level : Easy
Last Updated : 09 Jun, 2021
An array contains both positive and negative numbers in random order. 
Rearrange the array elements so that all negative numbers appear before all positive numbers.

Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
Note: Order of elements is not important here.*/


//Code in C++
#include <iostream>

using namespace std;
void sort_array(int arr[], int n){
    int j=0;    
    for(int i=0;i<n;i++){
        if(arr[i] < 0){
            if(i != j){
                swap(arr[i],arr[j]);   //swaping the negative element to the left side of array
            }
            j++;  //moving the pointer when we have an negative element 
        }
    }
}

int main() {
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int size_of_array = sizeof(arr) / sizeof(arr[0]);
	
	
	sort_array(arr,size_of_array);
	
	
	
	//print the array
	for(int i=0;i<size_of_array;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}