class Solution {
public:

   bool need(vector<int>& days, int required, int needFlowers, int guess){
   int currFlowers  = 0;
   int boquet = 0;

   for(int i = 0; i< days.size(); i++){
    if(days[i] > guess) currFlowers = 0;
    else{
        currFlowers++;
        if(currFlowers == needFlowers){
            boquet++;
            currFlowers = 0;
        }
    }

    if(boquet >= required) return true;
   }
    return false;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;

        while(low <= high){
            int guess = (low + high) / 2;
            bool isPossible = need(bloomDay, m, k, guess);

            if(isPossible == true){
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