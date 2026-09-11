class Solution {
private:
    void solve(int open, int close, vector<string> &ans, string &s){
        
        if(open == 0 and close == 0){
            ans.push_back(s);
            return;
        }

        if(open > 0){
            s.push_back('(');
            solve(open - 1, close, ans,s);
            s.pop_back();
        }

        if(open < close and close > 0){
            s.push_back(')');
            solve(open, close - 1, ans,s);
            s.pop_back();
        }
        //return;
    }
public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s = "";

        solve(n, n, ans,s);

        return ans;
        
    }
};
