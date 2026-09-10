class Solution {
private:
    int solve(int i, int jump, int n, vector<int> & nums, vector<vector<int>> &dp){
        //if(i >= n) return 0;
        if(i >= n - 1) return jump;

        if(dp[i][jump] != -1) return dp[i][jump];

        int mini = INT_MAX;

        for(int j = 1; j <= nums[i]; j++){
            mini = min(mini, solve(i+j,jump+1,n,nums,dp));
        }

        return dp[i][jump] = mini;
    }
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        // dp but O(N^2)
        //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

       // return solve(0,0,n,nums,dp);

        //T.C - O(N)
        //S.C - O(1)
       int left = 0;
       int right = 0;
       int jump = 0;

       while(right < n - 1){
            int farthest = 0;

            for(int i = left; i <= right; i++){
                farthest = max(i + nums[i], farthest);
            }

            left = right + 1;
            right = farthest;
            jump++;
       }

       return jump;
        
    }
};
