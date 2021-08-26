/*Question :- Find the median

Given an array arr[] of N integers, calculate the median
 

Example 1:

Input: N = 5
arr[] = 90 100 78 89 67
Output: 89
Explanation: After sorting the array 
middle element is the median 

Example 2:

Input: N = 4
arr[] = 56 67 30 79â€‹
Output: 61
Explanation: In case of even number of 
elemebts average of two middle elements 
is the median

 

Your Task:
You don't need to read or print anything. Your task is to complete the function find_median() which takes the array as input parameter and returns the floor value of the median.
 

Expected Time Complexity: O(n * log(n))
Expected Space Complexity: O(1)*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    int len = v.size();
		    sort(v.begin(),v.end());
		    if(len % 2 == 0){
		        return (v[(len/2)-1] + v[len/2])/2;
		    }
		    else{
		        return v[(len-1)/2];
		    }
		}
};
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}