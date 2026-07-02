class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int guess = low + (high - low) / 2;

            if (nums[guess] == target)
                return guess;

            // Mid is in the left sorted part
            if (nums[guess] > nums[n - 1]) {

                if (target > nums[guess]) {
                    low = guess + 1;
                }
                else {
                    if (target >= nums[0]) {
                        high = guess - 1;
                    }
                    else {
                        low = guess + 1;
                    }
                }
            }

            // Mid is in the right second part
            else {

                if (target < nums[guess]) {
                    high = guess - 1;
                }
                else {
                    if (target <= nums[n - 1]) {
                        low = guess + 1;
                    }
                    else {
                        high = guess - 1;
                    }
                }
            }
        }

        return -1;
    }
};