/*Question :- Median in a row-wise sorted Matrix

Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)*/

#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        vector<int> median;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                median.push_back(matrix[j][i]);
            }
            
        }
        int n = median.size();
        sort(median.begin(),median.end());
        if(n % 2 == 0){
            return (median[(n/2)-1] + median[n/2])/2;
        }
        else{
            return median[((n+1)/2)-1];
        }
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}