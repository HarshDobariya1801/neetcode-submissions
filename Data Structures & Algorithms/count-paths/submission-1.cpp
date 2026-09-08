class Solution {
private:
    int solve(int i, int j, vector<vector<int>> & dp){
        if(i == 0 and j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        // up = i - 1;
        int up = 0;
        if(i - 1 >= 0){
            up = solve(i-1,j,dp);
        }

        // left = j - 1;
        int left = 0;
        if(j - 1 >= 0){
            left  = solve(i,j-1,dp);
        }

        return dp[i][j] = {up + left};
    }
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));

        return solve(m-1,n-1,dp);
        
    }
};
