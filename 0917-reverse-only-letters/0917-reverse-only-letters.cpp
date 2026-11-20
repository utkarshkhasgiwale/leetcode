class Solution {
public:
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
    }
    string reverseOnlyLetters(string s) {

        int x = 0;
        int y = s.size() - 1;

        while(x < y){
             if (isLetter(s[x]) == 1 && isLetter(s[y]) == 1) {
            swap(s[x], s[y]);
            x++;
            y--;
        } else if (!isLetter(s[x]))
            x++;
        else
            y--;
    }
    return s;
}
};