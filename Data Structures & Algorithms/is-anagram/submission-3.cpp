class Solution {
public:
    bool isAnagram(string s, string t) {

        int sLength = s.length();
        int tLength = t.length();

        if(sLength != tLength) return false;

        sort(s.begin(), s.end());  // time complexity - O(nlogn)
        sort(t.begin(), t.end());

        if(s == t) return true;
        return false;


        
    }
};
