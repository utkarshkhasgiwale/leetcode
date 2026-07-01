class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = 0;

        while(low <= high){
            int guess = (low + high)/2;
            // int index = (guess + 1) % n;
            if(nums[guess] > nums[n - 1]){
                low = guess + 1;
            }
            else{
                res = nums[guess];
                high = guess - 1;
            }
        }
        return res;
    }
};