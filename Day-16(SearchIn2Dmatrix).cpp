/*
  time complexity : O(log N)
  Space complexity : O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        int i=0,j=m-1;
        while(i<n and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        
        return false;
    }
};
