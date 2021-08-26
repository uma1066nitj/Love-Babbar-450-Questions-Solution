/*Question:- Sort an array of 0s, 1s and 2s

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int start=0;
        int mid =0;
        int high = n-1;
        int pivot = 1;
        while(mid <= high){
            if(a[mid] < pivot){
                int temp = a[start];
                a[start] = a[mid];
                a[mid] = temp;
                ++start;
                ++mid;
            }
            else if(a[mid] > pivot){
                int temp = a[high];
                a[high] = a[mid];
                a[mid] = temp;
                --high;
                
            }
            else{
                ++mid;
            }
        }
    }

};


int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}