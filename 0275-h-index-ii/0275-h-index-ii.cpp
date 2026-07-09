class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();
        int low  = 0;
        int high = n - 1;
        int res = 0;

        while(low <= high){

            int guess = (low + high) / 2;
            int paper = n - guess;
             if(citations[guess] >= paper){
                res = paper;
                high = guess - 1;
            }
            else low = guess + 1;
        }
        return res;
    }
};