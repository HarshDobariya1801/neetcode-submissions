class Solution {
private:
    int solve(int i, int j, int n, int m, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = 0;
        if(i - 1 < n and i - 1>= 0 and grid[i-1][j] > grid[i][j]){
            up = solve(i-1,j,n,m,grid,dp);
        }

        int left = 0;
        if(j - 1 < m and j - 1 >= 0 and grid[i][j-1] > grid[i][j]){
            left = solve(i,j-1,n,m,grid,dp);
        }

        int down = 0;
        if(i + 1 < n and i + 1>= 0 and grid[i+1][j] > grid[i][j]){
            down = solve(i+1,j,n,m,grid,dp);
        }

        int right = 0;
        if(j + 1 < m and j + 1 >=0 and grid[i][j+1] > grid[i][j]){
            right = solve(i,j+1,n,m,grid,dp);
        }

        return dp[i][j] = 1 + max({left,right,up,down});
    }   
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans,solve(i,j,n,m,matrix,dp));
            }
        }

        return ans;
        
    }
};
