/*Question :- Spirally traversing a matrix

Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
              {5, 6, 7, 8},
              {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(r*c)
Expected Auxiliary Space: O(r*c), for returning the answer only.*/




#include <bits/stdc++.h> 
using namespace std; 
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
       int row_start = 0,row_end = r-1,column_start = 0,column_end = c-1;
       vector<int> answer;
       while(row_start<=row_end && column_start<=column_end){
           for(int row = column_start;row<=column_end;row++){
               answer.push_back(matrix[row_start][row]);
           }
           row_start++;
           
           for(int col= row_start;col<=row_end;col++){
               answer.push_back(matrix[col][column_end]);
           }
           column_end--;
           
           if(row_start<=row_end){
               for(int row = column_end;row>=column_start;row--){
                    answer.push_back(matrix[row_end][row]);
                }
                row_end--;
            }
            
            if(column_start<=column_end){
                for(int col = row_end;col>=row_start;col--){
                    answer.push_back(matrix[col][column_start]);
                }
                column_start++;
            }
       }
       return answer;
    }
};
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}