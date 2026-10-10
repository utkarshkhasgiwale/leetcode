class Solution {
public:
    bool isPalindrome(string s) {
        bool ans = true;
        int high = s.length()-1;
        int low = 0;

        while(low <= high){
            while(!isalnum(s[low]) && low <= high) low++;

            while(!isalnum(s[high]) && low <= high) high--;

            if(low > high) break;

            s[low] = tolower(s[low]);
            s[high] = tolower(s[high]);

            if(s[low] != s[high]) {
                ans = false;
                break;
            }
            else{
                low++;
                high--;
            }
        }
        return ans;
        
    }
};