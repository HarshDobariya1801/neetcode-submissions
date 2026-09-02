class Solution {
private:
    void dfs(int row, int col,int n, int m, vector<vector<char>> &adj){

        if(row < 0 || row >= n || col < 0 || col >= m || adj[row][col] != '1'){
            return;  
        }

        adj[row][col] = '2';

        dfs(row+1,col,n,m,adj);
        dfs(row-1,col,n,m,adj);
        dfs(row,col+1,n,m,adj);
        dfs(row,col-1,n,m,adj);
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<char>> adj = grid;

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(adj[i][j] == '1'){
                    ans++;
                    dfs(i,j,n,m,adj);
                }
            }
        }

        return ans;
        
    }
};
