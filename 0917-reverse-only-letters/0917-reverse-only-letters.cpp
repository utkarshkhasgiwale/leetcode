class Solution {
public:
    string reverseOnlyLetters(string s) {
        int x = 0;
        int y = s.size() - 1;

        while(x < y){
            if(isalpha(s[x]) && isalpha(s[y])){
                swap(s[x], s[y]);
                x++;
                y--;
            }
            else if(!isalpha(s[x])) x++;
            else y--;
        }
        return s;
    }
};