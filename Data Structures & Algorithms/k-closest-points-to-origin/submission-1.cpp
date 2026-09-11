class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // {dist, {i,j}}
        int n = points.size();
        // min heap
        priority_queue< pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>> > pq;

        for(auto it : points){
            int x1 = it[0];
            int y1 = it[1];
            int x = abs(it[0]);
            int y = abs(it[1]);


            int dist = (x * x) + (y * y);
            pq.push({dist, {x1,y1}});
        }

        vector<vector<int>> ans;
        while(k--){
           int x =  pq.top().second.first;
           int y = pq.top().second.second;
           pq.pop();
           ans.push_back({x,y});
            
        }

        return ans;
        
    }
};
