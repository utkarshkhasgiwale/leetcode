class Solution {
public:

    bool noOfCandies(vector<int>& candy, int n, long long requiredStudents, int guess){
        
        long long totalStudents = 0;
        for(int i = 0; i< n; i++){
          int currStudents = candy[i] / guess;
          totalStudents += currStudents;

           if (totalStudents >= requiredStudents)
            return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low  = 1;
        int high = *max_element(candies.begin(), candies.end());
        int res = 0;

        while(low <= high){
            int guess = (low + high) / 2;
            bool canGiven = noOfCandies(candies, n, k, guess);

            if(canGiven){
                res = guess;
                low  = guess + 1;
          }
          else{
            high = guess - 1;
          }
        }
      return res;
    }
};