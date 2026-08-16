class Solution {
public:

    void fun(int n, int close, int open, string& temp, vector<string>& res){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            fun(n, close, open + 1, temp, res);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            fun(n, close + 1, open, temp, res);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        fun(n, 0, 0, temp, res);

        return res;
    }
};