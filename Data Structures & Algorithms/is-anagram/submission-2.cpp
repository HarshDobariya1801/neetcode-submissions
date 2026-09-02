class Solution {
public:
    bool isAnagram(string s, string t) {

        int sLength = s.length();
        int tLength = t.length();

        if(sLength != tLength) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());


        for(int i = 0; i < sLength; i++){
            if(s[i] != t[i]) return false;
        }

        return true;


        
    }
};
