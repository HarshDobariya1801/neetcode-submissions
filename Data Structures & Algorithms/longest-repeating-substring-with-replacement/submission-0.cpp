class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26);
        int left = 0;
        int maxFreq = 0;
        int maxWindow = 0;
        int right = 0;
        int n = s.size();

        while(right < n){

            // update the freq of the current characte
            v[s[right] - 'A']++;

            // update the max freq
            maxFreq = max(maxFreq, v[s[right] - 'A']);

            int windowLength = right - left + 1;

            // if the windowLength - maxFreq > k,
            // then we need to shrink the window
            if(windowLength - maxFreq > k){
                v[s[left] - 'A']--;
                left++;
            }

            windowLength = right - left + 1;
            maxWindow = max(maxWindow, windowLength);

            right++;
        }

        return maxWindow;
    }
};
