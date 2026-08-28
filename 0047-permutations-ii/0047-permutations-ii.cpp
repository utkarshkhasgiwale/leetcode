class Solution {
public:

    void fun(vector<int>& nums, int n, int i, vector<bool>& used, vector<int>& dairy, vector<vector<int>>& res){
        if(dairy.size() == n){
            res.push_back(dairy);
            return;
        }

        for(int j = 0; j < n; j++){

           if(used[j] == true) continue;

           else if(j > 0 && nums[j] == nums[j-1] && !used[j-1]) continue;

            dairy.push_back(nums[j]);
            used[j] = true;

            fun(nums, n, i+1, used, dairy, res);
            
            dairy.pop_back();
            used[j] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        vector<bool> used(n, false);
        vector<int> dairy;
        vector<vector<int>> res;

        fun(nums, n, i, used, dairy, res);
        return res;
    }
};