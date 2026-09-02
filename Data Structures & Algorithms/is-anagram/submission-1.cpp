class Solution {
public:
    bool isAnagram(string s, string t) {

        // int n = s.size();
        // int n1 = t.size();

        // map<char,int> m;

        // for(int i = 0; i < n; i++){
        //     m[s[i]]++;
        // }

        // for(int i = 0; i <n1; i++){
        //     m[t[i]]++;
        // }

        // for(auto it:m){
        //     if(it.second%2 != 0) return false;
        // }

        // return true;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t) return true;
        
        return false;

        
    }
};
