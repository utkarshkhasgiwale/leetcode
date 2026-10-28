class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int low = 0;
        int high = 1;

        while(low < nums.size() && high < nums.size())
        {
            if(nums[low] % 2 == 0) low += 2;
            else{
                if(nums[high] % 2 != 0) high += 2;
                else{
                    swap(nums[low], nums[high]);
                    low += 2;
                    high += 2;
                }
            }
        }
        return nums;
    }
};