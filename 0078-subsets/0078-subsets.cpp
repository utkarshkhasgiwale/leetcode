class Solution {
public:
   void fun(vector<int>& nums, int n, int i, vector<int>& dairy, vector<vector<int>>& res){
    if(i == n){
        res.push_back(dairy);
        return;
    }
    
    fun(nums, n, i + 1, dairy, res);
    
    dairy.push_back(nums[i]);
    fun(nums, n, i+1, dairy, res);
    dairy.pop_back();
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dairy;
        vector<vector<int>> res;
        int i = 0;

        fun(nums, n , i, dairy, res);
        return res;
        
    }
};