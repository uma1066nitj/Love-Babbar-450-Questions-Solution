//Question :- Maximum and minimum of an array using minimum number of comparisons

#include <iostream>
using namespace std;

void get_min_max(int arr[], int arr_size){
    int min = arr[0];
    int max = arr[1];
    
    if(arr_size == 1){
        min = arr[0];
        max = arr[0];
    }
    if(arr_size>1){
        if(arr[0]<arr[1]){
            min = arr[0];
            max = arr[1];
        }
        else{
            min = arr[1];
            max = arr[0];
        }
        
        for(int i=0;i<arr_size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
        }
    }
    cout<<"Maximum element is "<<max<<endl;
    cout<<"Minimum element is "<<min<<endl;
}
int main() {

    int arr_size;
    //Enter Size of array
    cin>>arr_size;
    int arr[arr_size];
    //Enter element of array
    for(int i=0;i<arr_size;i++){
        cin>>arr[i];
    }
    
    
    get_min_max(arr, arr_size);
      
    
	return 0;
}