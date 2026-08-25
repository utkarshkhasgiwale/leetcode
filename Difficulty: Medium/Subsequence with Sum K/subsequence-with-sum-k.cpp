class Solution {
public:

    bool fun(vector<int>& arr, int k, int n, int i, int sum,
             vector<int>& dairy, vector<vector<int>>& res) {

        if (i == n) {
            if (sum == k) {
                res.push_back(dairy);
                return true;
            }
            return false;
        }

        // Don't take
        if (fun(arr, k, n, i + 1, sum, dairy, res)) {
            return true;
        }

        // Take
        if (sum + arr[i] <= k) {

            dairy.push_back(arr[i]);
            sum += arr[i];

            if (fun(arr, k, n, i + 1, sum, dairy, res)) {
                return true;
            }

            dairy.pop_back();
            sum -= arr[i];
        }

        return false;
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {

        int n = arr.size();
        int i = 0;
        int sum = 0;

        vector<int> dairy;
        vector<vector<int>> res;

        return fun(arr, k, n, i, sum, dairy, res);
    }
};