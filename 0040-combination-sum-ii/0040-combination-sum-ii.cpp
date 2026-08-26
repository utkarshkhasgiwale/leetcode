class Solution {
public:
    void fun(vector<int>& candidates, int target, int n, int i,
             vector<int>& dairy, vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(dairy);
            return;
        }

        for(int j = i; j < n; j++){
            if(j > i && candidates[j] == candidates[j-1]) continue;

            if(candidates[j] > target) break;

            dairy.push_back(candidates[j]);

            fun(candidates, target - candidates[j], n, j+1, dairy, res);

            // Backtrack
            dairy.pop_back();
        }
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        int i = 0;
        // int sum = 0;

        vector<int> dairy;
        vector<vector<int>> res;

        fun(candidates, target, n, i, dairy, res);

        return res;
    }
};