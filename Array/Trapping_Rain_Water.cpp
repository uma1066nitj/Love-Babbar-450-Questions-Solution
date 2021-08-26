/*Question :- Trapping Rain Water

Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.

Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.

Your Task:
You don'y need to read input or print anything. The task is to complete the function trappingWater() which takes arr and N as input parameters and returns the total amount of water that can be trapped.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/

// Code with Time Complexity of O(N^2)

#include<bits/stdc++.h>

using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int trapped_water = 0;
        for(int i =0;i<n;i++){
            
            int Lmax = arr[i]; //left max
            for(int j =0;j<i;j++){
                Lmax = max(Lmax, arr[j])    ;
            }
            
            int rmax = arr[i];//right max
            for(int j=i+1;j<n;j++){
                rmax = max(rmax,arr[j]);
            }
            
            trapped_water += (min(Lmax,rmax) - arr[i]);
        }
        return trapped_water;
    }
};


int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}

// Code with Time Complexity of O(N) and Space Complexity with O(N)

#include<bits/stdc++.h>

using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int trapped_water = 0;
        int lmax[n]; lmax[0] = arr[0]; //decleare a left array
        for(int i = 1;i<n;i++){
            lmax[i] = max(lmax[i-1], arr[i]);
        }
        int rmax[n]; rmax[n-1] = arr[n-1];//decleare a right array
        for(int i =n-2;i>=0;i--){
            rmax[i] = max(rmax[i+1],arr[i]);
        }
        //total water stored
        for(int i = 1;i<n-1;i++){
            trapped_water += (min(lmax[i],rmax[i]) - arr[i]);
        }
        
        return trapped_water;
    }
};

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}