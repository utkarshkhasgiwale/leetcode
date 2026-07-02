class Solution {
public:

   long long banans(vector<int> &nums, int target){
    long long total = 0;
    int i = 0;
    while(i < nums.size()){
    int div = nums[i] / target;
    int mod = nums[i] % target;

    if(mod == 0)
     total += div;
    else 
     total += div + 1;

    i++;
    }
    return total;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = INT_MAX;
        
        while(low <= high){
            int guess = (low + high) / 2;
           long long total = banans(piles, guess);
            if(total > h) low = guess + 1;
            else{
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};