class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        int ans = 0;
        int cnt = 0;

        for(auto it : st){
            int temp = it;
            if(st.find(temp-1) == st.end()){
                cnt++;
                while(st.find(temp + 1) != st.end()){
                    cnt++;
                    temp++;
                }

            }
            ans = max(ans,cnt);
            cnt = 0;
        }

        return ans;

        
    }
};
