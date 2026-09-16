// class Solution {
// public:
//     string minWindow(string s, string t) {

//         int n = s.size();
//         int m = t.size();

//         string ans = "";

//         if(m > n) return ans;

//         vector<int> freq(26,0);
//         int left = 0, right = 0;
//         int minLen = 1e9;
//         int startInd = -1;
//         int cnt = 0;

//         for(int i = 0; i < m; i++){
//             freq[t[i] - 'a']++;
//         }

//         while(right < n){
//             if(freq[s[right] - 'a'] > 0){
//                  cnt++;
//                  freq[s[right] - 'a']--;

//                  if(cnt == m){
//                     if(right - left + 1 < minLen){
//                         minLen = right - left + 1;
//                         startInd = left;
//                     }
//                  }

//                  freq[s[left] -'a']--;
//                  if(freq[s[left]] > 0) cnt--;
//                  right++;
//             }
//         }

//         if(startInd == -1) return "";
//         return s.substr(startInd, m);

        

//     }
// };
class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        if (m > n) return "";

        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int right = 0;

        int cnt = 0;

        int minLen = 1e9;
        int startInd = -1;

        while (right < n) {

            // If this character is still needed
            if (freq[s[right]] > 0) {
                cnt++;
            }

            // Include current character in window
            freq[s[right]]--;

            // If window contains all characters of t
            while (cnt == m) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startInd = left;
                }

                // Remove left character
                freq[s[left]]++;

                // If after removing it, we now need this character again
                if (freq[s[left]] > 0) {
                    cnt--;
                }

                left++;
            }

            right++;
        }

        if (startInd == -1) return "";

        return s.substr(startInd, minLen);
    }
};
