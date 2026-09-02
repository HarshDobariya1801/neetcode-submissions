class Solution {
public:
    bool isAnagram(string s, string t) {

        // int sLength = s.length();
        // int tLength = t.length();

        // if(sLength != tLength) return false;

        // sort(s.begin(), s.end());  // time complexity - O(nlogn)
        // sort(t.begin(), t.end());

        // if(s == t) return true;
        // return false;


        if(s.length() != t.length()){
             return false;
        }

        unordered_map<char,int> cntS;
        unordered_map<char,int> cntT;

        for(int i = 0; i < s.length(); i++){
            cntS[s[i]]++;
            cntT[t[i]]++;

        }

        return cntS == cntT;


        
    }
};
