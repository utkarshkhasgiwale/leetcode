class Solution {
public:

    void fun(vector<int>& nums, int n, vector<int>& dairy, vector<vector<int>>& res, vector<bool>& used){
        if(dairy.size() == n){
            res.push_back(dairy);
            return;
        }

        for(int j = 0; j < n; j++){
              
        if(used[j] == true){
            continue;
        }
        else{
            dairy.push_back(nums[j]);
            used[j] = true;
            fun(nums, n,  dairy, res, used);
            dairy.pop_back();
            used[j] = false;
        }
        }
    
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        // int i = 0;
        vector<int> dairy;
        vector<vector<int>> res;
        vector<bool> used(n, false);

        fun(nums, n, dairy, res, used);
        return res;
    }
};