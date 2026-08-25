class Solution {
public:
    void fun(vector<int>& candidates, int n, int i, int sum, int target,
             vector<int>& dairy, vector<vector<int>>& res) {
        if (i == n) {
            if (sum == target)
                res.push_back(dairy);
            return;
        }

        fun(candidates, n, i + 1, sum, target, dairy, res);

        if (candidates[i] + sum <= target) {
            dairy.push_back(candidates[i]);
            sum += candidates[i];

            fun(candidates, n, i, sum, target, dairy, res);

            dairy.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        int i = 0;
        vector<int> dairy;
        vector<vector<int>> res;

        fun(candidates, n, i, sum, target, dairy, res);

        return res;
    }
};