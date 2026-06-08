class Solution {
public:
    void solve(int open, int close, int n, string&tmp, vector<string>&res) {
        if(open == n && close == n){
            res.push_back(tmp);
            return;
        }
        if(open<n){
            tmp.push_back('(');
            solve(open+1, close, n, tmp, res );
            tmp.pop_back();
        }
        if(close<open){
            tmp.push_back(')');
            solve(open, close+1, n, tmp, res);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        vector<string> res;
        string tmp;
        solve(0, 0, n, tmp, res);
        return res;
    }
};