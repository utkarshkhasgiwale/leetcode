class Solution {
public:

    int Counter(vector<vector<int>>& table, int m, int n, int target){
        int row = n -1;
        int col = 0;
        int count = 0;

        while(row >= 0 && col < m){
            if(table[row][col] <= target){
               count += row + 1;
               col++;
            }
            else{
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n-1][m-1];

        int res = -1;

        while(low <= high){
            int guess = (low + high) / 2;
            int smallestElement = Counter(matrix, n, m, guess);
            if(smallestElement < k){
                low = guess + 1;
            }
            else{
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};