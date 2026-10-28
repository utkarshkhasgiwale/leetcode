class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int high = nums.size()-1;
        int low = 0;
        while(low <= high)
        {
            if(nums[low] % 2 != 0){
                if(nums[high] % 2 == 0) swap(nums[low], nums[high]);
                else{
                    high--;
                }
            }
            else{
                low++;
            }
        }
        return nums;
    }
};