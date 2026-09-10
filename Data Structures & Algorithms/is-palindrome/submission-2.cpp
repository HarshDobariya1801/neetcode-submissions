class Solution {
private:
    bool ans(string t){

        int n = t.size();

        for(int i = 0; i < n/2; i++){
            if(t[i] != t[n-i-1]) return false;
        }
        return true;

    }
public:
    bool isPalindrome(string s) {

        string t;

        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == ' ') continue;
           if((s[i] >= 65 && s[i] <= 90) || s[i] >= 97 and s[i] <= 122 || s[i] >= 48 and s[i] <= 57)
                t += (char)tolower(s[i]);
        }    
   

        return ans(t);
    }
};
