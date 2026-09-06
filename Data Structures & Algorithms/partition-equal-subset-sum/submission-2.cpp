class Solution {
private:
    bool solve(int i, int n, vector<int> &nums, int target, vector<vector<int>> & dp){
        if(target == 0) return true;
        if(i == 0) return (nums[0] == target);

        if(dp[i][target] != -1) return dp[i][target];

        bool notPick = solve(i-1,n,nums,target,dp);

        bool pick = false;
        if(nums[i] <= target){
            pick = solve(i-1,n,nums, target-nums[i],dp);
        }

        return dp[i][target] = (notPick | pick);
    }
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum%2) return false;

        int target = sum/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        return solve(n-1,n,nums,target,dp);

        
    }
};
