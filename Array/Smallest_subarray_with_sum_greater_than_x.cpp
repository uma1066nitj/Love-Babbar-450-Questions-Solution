/*Question :- Smallest subarray with sum greater than x

Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function sb() which takes the array A[], its size N and an integer X as inputs and returns the required ouput.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)*/

//code with  Time Complexity: O(N^2)

#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here 
        int min_len = n+1;
        for(int i=0;i<n;i++){
            int curr_sum = arr[0];
            
            if(curr_sum > x){
                return 1;
            }
            
            for(int j=i+1;j<n;j++){
                curr_sum += arr[j];
                if(curr_sum > x && (j-i+1) < min_len){
                    min_len = (j-i+1);
                }
            }
        }
        return min_len;
    }
};

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}

//code with  Time Complexity: O(N) and space complexity  O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int curr_sum = 0;
        int min_len = n+1;
        int start = 0, end = 0;
        while(end < n){
            while(curr_sum <= x && end<n){
                curr_sum += arr[end++];
            }
            while(curr_sum >x && start<n){
                if(end - start < min_len){
                min_len = end - start;
            }
            curr_sum -= arr[start++];
            }
            
        }
        return min_len;
        
    }
};

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}