class Solution {
private:
    int solve(int i, int t, vector<int> &a,vector<vector<int>> &dp){
        if(i == 0) return (t%a[0] == 0);

        if(dp[i][t] != -1) return dp[i][t];

        int take = 0;

        if(a[i] <= t)
            take = solve(i,t-a[i],a,dp);

        int notTake = solve(i-1,t,a,dp);

        return dp[i][t] = (take + notTake);

    }
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1,-1));

        return solve(n-1,amount,coins,dp);
        
    }
};
