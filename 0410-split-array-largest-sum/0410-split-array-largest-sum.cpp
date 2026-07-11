class Solution {
public:

    bool currLargestSum(vector<int>& nums, int k, int guess){
        int subArray = 1;
        int currSubArraySum = 0;

        for(int i = 0; i< nums.size(); i++){
            int tempNext = nums[i];
            if((currSubArraySum + tempNext) > guess){
                subArray++;
                currSubArraySum = nums[i];
            }
            else{
                currSubArraySum += nums[i];
            }
        }
        return subArray <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        int res = 0;

        for(int x : nums) high += x;

        while(low <= high){
            int guess = (low + high) / 2;
            bool largestSum = currLargestSum(nums, k, guess); 
            if(largestSum){
                res = guess;
                high = guess - 1;
            }
            else{
                low = guess + 1;
            }
        }
         return res;
    }
};