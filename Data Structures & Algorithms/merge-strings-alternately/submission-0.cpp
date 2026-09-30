class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string ans =  "";
        int n = word1.size();
        int m = word2.size();

        int z = max(n, m);

        for(int i = 0; i < z; i++){
            if(i < n){
                ans += word1[i];
            }
            if(i < m){
                ans += word2[i];
            }
        }

        return ans;
        
    }
};