class Solution {
private:
    void solve(int i, string &digits, string &s, vector<string> &ans, string map[]){
        if(i >= digits.size()){
            ans.push_back(s);
            return;
        }

        int num = digits[i] - '0';
        string temp = map[num];

        for(int j = 0; j < temp.size(); j++){
            s += temp[j];
            solve(i + 1, digits, s,ans,map);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {

        string s = "";
        vector<string> ans;
        if(digits.size() == 0) return ans;

        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(0,digits, s, ans, map);

        return ans;
        
    }
};
