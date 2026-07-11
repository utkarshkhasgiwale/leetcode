class Solution {
public:

    bool noOfDays(vector<int>& weights, int days, int guess){
        int totalDays = 1;
        int currWeight = 0;
        for(int i = 0; i < weights.size(); i++){
          int tempCurrWeight = weights[i];
          if(currWeight + tempCurrWeight <= guess){
            currWeight += weights[i];
          }
          else{
            totalDays++;
            currWeight = weights[i];
          }
        }
       return totalDays <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high  = 0;
        int res = 0;

        for (int x : weights){
            high += x;
        }

        while(low <= high){
            int guess = (low + high) / 2;
            bool noOfDaysRequired = noOfDays(weights, days, guess);
            if(noOfDaysRequired){
             res = guess;
             high = guess - 1;
            }
            else {
            low = guess + 1;
            }
        }
        return res;
    }
};