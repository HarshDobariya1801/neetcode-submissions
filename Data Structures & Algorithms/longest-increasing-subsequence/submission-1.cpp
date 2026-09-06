class Solution {
private:
    int solve(int i, int prev_ind,int n, vector<int> &nums, vector<vector<int>> &dp){
        if(i == n) return 0;

        if(dp[i][prev_ind+1] != -1) return dp[i][prev_ind+1];

        int len = 0 + solve(i+1, prev_ind,n,nums,dp);
        if(prev_ind == -1 || nums[i] > nums[prev_ind]){
            len = max(len,1 + solve(i+1, i,n,nums,dp));
        }

        return dp[i][prev_ind+1] = len;
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));

        return solve(0,-1,n,nums,dp);

    }
};
