class Solution {
private:
    int solve(int i, vector<int> &v, vector<int> &dp){
        // if(i == 0) return v[0];
        // if(i < 0) return 0;

        // if(dp[i] != -1) return dp[i];

        // int notTake = 0 + solve(i -1 , v, dp);
        // int take = v[i] + solve(i - 2, v, dp);

        // return dp[i] = max(notTake, take);

        dp[0] = v[0];
        int n = v.size();

        for(int i = 1; i < n; i++){
            int take = v[i];
            if(i > 1){
                take = take + dp[i-2];
            }
            int notTake = dp[i-1];

            dp[i] = max(notTake,take);
        }

        return dp[n - 1];
    }
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> v1,v2;

        for(int i = 0; i < n; i++){
            if(i != 0){
                v1.push_back(nums[i]);
            }

            if(i != n - 1){
                v2.push_back(nums[i]);
            }
        }

        int size1 = v1.size();
        int size2 = v2.size();
        vector<int> dp1(size1+1,-1), dp2(size2+1,-1);
        return max(solve(size1 - 1, v1,dp1), solve(size2 - 1, v2,dp2));
        
    }
};
