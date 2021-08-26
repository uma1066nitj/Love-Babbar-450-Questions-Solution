/*Question :- Minimize the Heights II 

Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once. 
After modifying, height should be a non-negative integer. Find out what could be the possible minimum 
difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between 
the largest and the smallest is 17-6 = 11.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)*/

#include <bits/stdc++.h>
using namespace std;

 // User function template for C++

class Solution {
  public:
  int maximum(int i, int j){
      if(i<j){
          return j;
      }
      else{
          return i;
      }
    }
    int minimum(int i, int j){
        if(i < j){
            return i;
        }
        else{
            return j;
        }
    }
  
    int getMinDiff(int arr[], int n, int k) {
        // code here
        int min = 0, max = 0, r = 0;
        sort(arr,arr+n);   //arranging the array in increasing order
        r = arr[n-1] - arr[0];  /*initial difference between the first and 
                                last element that will be base to compare*/
        
        for(int i=0;i<n;i++){
            if(arr[i] >= k){   //when we subtract the k from arays element that will come negative until 
                                //the element is greater than or equal to k.
                max = maximum(arr[i-1]+k,arr[n-1]-k);  /*arr[i-1] elements means where we cannot subract k from 
                               array element. so there we have to add the k and from the largest subtract the k, 
                               to find which one is maximum.*/
                min = minimum(arr[i]-k,arr[0]+k); /*arr[i] this is the first element where I can subtract 
                                k from that and add k in first element arr[0] to find out which one is minimum*/
                r = minimum(r,max-min);  /*compare the result without add or subtract value of k and 
                                with add or subtract value of k from array elements and choose minimum 
                                in that.*/
            }
            else{
                continue;
            }
        }
        return r;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}