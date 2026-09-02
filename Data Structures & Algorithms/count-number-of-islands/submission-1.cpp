class Solution {
// private:
//     void dfs(int row, int col,int n, int m, vector<vector<char>> &adj){

//         if(row < 0 || row >= n || col < 0 || col >= m || adj[row][col] != '1'){
//             return;  
//         }

//         adj[row][col] = '2';

//         dfs(row+1,col,n,m,adj);
//         dfs(row-1,col,n,m,adj);
//         dfs(row,col+1,n,m,adj);
//         dfs(row,col-1,n,m,adj);
//     }
private:
    void bfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,-1,0,1};

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and grid[nrow][ncol] == '1' and !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int ans = 0;
        

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }

        return ans;




        // dfs
        // int ans = 0;

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(adj[i][j] == '1'){
        //             ans++;
        //             dfs(i,j,n,m,adj);
        //         }
        //     }
        // }

        // return ans;
        
    }
};
