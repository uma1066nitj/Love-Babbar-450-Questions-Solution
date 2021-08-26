// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
 
// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Approach - I 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};


// Approach - II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int flag;
        if(row == 1){
            for(int j=0;j<col;j++){
                if(matrix[0][j] == target){
                    return true;
                }
            }
        }
        else if(row > 1){
            for(int i=row-1;i>=0;i--){
                if(matrix[i][0] < target){
                    flag = i;
                    break;
                }
            }
            for(int j=0;j<col;j++){
                if(matrix[flag][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};


// Approach - III
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 0) return false;
        int start = 0, end = row-1,mid;
        
        while(start<end){
            mid = start + (end-start)/2;
            
            if(matrix[mid][col-1] < target){
                start = mid +1;
            }
            else if(matrix[mid][0] > target){
                end = mid - 1;
            }
            else{
                start = mid;
                break;
            }
        }
        int col_start = 0, col_end = col-1;
        while(col_start <= col_end){
            mid = col_start + (col_end - col_start)/2;
            if(matrix[start][mid] < target){
                col_start = mid +1;
            }
            else if(matrix[start][mid] > target){
                col_end = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};

