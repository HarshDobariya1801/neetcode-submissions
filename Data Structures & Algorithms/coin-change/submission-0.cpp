class Solution {
private:
    int solve(int i, int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
        
        if(i == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }

        if(dp[i][amount] != -1) return dp[i][amount];
        
        int notTake =  0 + solve(i-1,n,amount,coins,dp);
        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + solve(i,n,amount-coins[i], coins,dp);
        }

        return dp[i][amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n+1,vector<int>(amount+1, -1));

        int ans = solve(n-1,n,amount, coins,dp);

        if(ans == 1e9) return -1;
        return ans;
        
    }
};
