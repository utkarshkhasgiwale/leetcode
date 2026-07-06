class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = (m*n) - 1;

        while(low <= high){
            int guess = (low + high) / 2;
            int row = guess / m;
            int col = guess % m;

            if(matrix[row][col] < target) low = guess + 1;
            else if(matrix[row][col] > target) high = guess - 1;
            else {
                return true;
            }
        }
        return false;
    }
};