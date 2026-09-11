class Solution {
private:
    int solve(int i, vector<int> & cost, vector<int> &dp){
        if(i < 0) return 0;
        //if(i == 0 || i == 1) return cost[i];
        if(dp[i] != -1) return dp[i];
        //if(i == 0) return cost[0];

        int firstStep = cost[i] + solve(i - 1, cost,dp);
        int twoStep = cost[i] + solve(i - 2, cost,dp);

        return dp[i] = min(firstStep, twoStep);
        //return cost[i] + min(solve(i-1,cost),solve(i-2,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n + 1,-1);

        return min(solve(n-1, cost,dp), solve(n - 2, cost,dp));
        
    }
};
