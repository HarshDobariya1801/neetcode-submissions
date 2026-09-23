class Solution {
private:
    bool isValid(int row, int col, int n, int m){
        return (row >= 0 and row < n and col >=0 and col < m);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visGrid(n,vector<int>(m,0));

        // {{i,j},time}
        queue<pair<pair<int,int>,int>> q;
        
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 2){
                    //bfs(row,col,n,m,grid)
                    q.push({{row,col},0});
                    visGrid[row][col] = 2;
                }
            }
        }

        int ans = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans,time);

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(isValid(nrow,ncol,n,m) and grid[nrow][ncol] == 1 and visGrid[nrow][ncol] != 2){
                    q.push({{nrow,ncol},time+1});
                    visGrid[nrow][ncol] = 2;
                }
            }   
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 and visGrid[i][j] != 2) return -1;
            }
        }

        return ans;
        
    }
};
