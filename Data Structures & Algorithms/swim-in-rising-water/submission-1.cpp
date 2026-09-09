class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m,1e9));

        //priority_queue<pair<int,pair<int,int>>> pq;
        priority_queue<pair<int,pair<int,int>>, 
            vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n - 1 and col == m - 1) return diff;

            for(int i = 0; i < 4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m){
                    int newHeight = max(diff,grid[nrow][ncol]);
                    if(newHeight < dist[nrow][ncol]){
                        dist[nrow][ncol] = newHeight;
                        pq.push({newHeight,{nrow,ncol}});
                    }
                }
            }
        }

        return 0;
        
    }
};
