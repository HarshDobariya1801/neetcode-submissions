// class Solution {
// private:
//     void bfs(int i,int j, int n,int m,vector<vector<int>> &grid,int &cnt){

//         if(i < 0 || j < 0 || i > n || j > m || grid[i][j] != 1){
//             return ;
//         }

//         grid[i][j] = 0;
//         cnt++;

//         bfs(i+1,j,n,m,grid,cnt);
//         bfs(i-1,j,n,n,grid,cnt);
//         bfs(i,j+1,n,m,grid,cnt); 
//         bfs(i,j-1,n,m,grid,cnt);

//     }
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {

//         int n = grid.size();
//         int m = grid[0].size();

//         int ans = 0;

//         for(int row = 0; row < n; row++){
//             for(int col = 0; col < m; col++){
//                 if(grid[row][col] == 1){
//                     int cnt = 0;
//                    bfs(row,col,n-1,m-1,grid,cnt);
//                    ans = max(ans,cnt);
//                 }
//             }
//         }

//         return ans;
        
//     }
// };
class Solution {
private:
    void bfs(int i,int j,int row, int col, vector<vector<int>> &grid,int &cnt){
        
        if(i < 0 || j < 0 || i > row || j > col || grid[i][j] != 1) return;
        
        grid[i][j] = 0;
        cnt++;
        bfs(i+1,j,row,col,grid,cnt);
        bfs(i-1,j,row,col,grid,cnt);
        bfs(i,j+1,row,col,grid,cnt);
        bfs(i,j-1,row,col,grid,cnt);
    }
       
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col  = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    bfs(i,j,row-1,col-1,grid,cnt);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
