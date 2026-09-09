class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        if(n == 0) return 0;
        if(n == 1) return 1;

        map<char,int> m;

        int l = 0, r = 0;

        int ans = 0;

        int len = 0;

        while(r < n){
            if(m.find(s[r]) != m.end()){
                if(m[s[r]] >= l){
                     l = m[s[r]] + 1;
                }  
            }
            len = r - l + 1;
            ans = max(ans,len);
            m[s[r]] = r;
            r++;
            
        }

        return ans;
        
    }
};
