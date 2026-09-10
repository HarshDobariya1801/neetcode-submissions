class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return true;

        int maxIndex = 0;

        for(int i = 0; i < n; i++){
            if(maxIndex < i) return false;
            int jump = i + nums[i];
            maxIndex = max(jump,maxIndex);
        }

        return true;
        
    }
};
