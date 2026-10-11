class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int high = nums.size()-1;
        int low = 0;
        int count = 0;

        while(low <= high){
            if(nums[low] != val){
                count++;
                low++;
            }
            else{
                if(nums[high] == val) high--;
                else{
                    swap(nums[low], nums[high]);
                    low++;
                    high--;
                    count++;
                }
            }
        }
        return count;
    }
};