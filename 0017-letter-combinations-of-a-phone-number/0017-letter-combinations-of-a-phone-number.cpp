class Solution {
public:

    void fun(string &digits, int n, int i, string &dairy, vector<string> &res, unordered_map<char, string> &f){
        if(i == n){
            res.push_back(dairy);
            return;
        }

        string choices = f[digits[i]];

        for(int j = 0; j < choices.size(); j++){
           dairy.push_back(choices[j]);
           fun(digits, n, i+1, dairy, res, f);
           dairy.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        int i = 0;
        int n = digits.size();
        string dairy = "";
        vector<string> res;

        fun(digits, n, i, dairy, res, f);
        return res;
    }
};