class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> graph(n+1);

        //vector<vector<<pair<int,int>>> graph(n);

        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            graph[u].push_back({v,t});
        }

        vector<int> dist(n+1,1e9);

        // {dist,node}
        //queue<pair<int,int>> q;
        int ans = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto &it : graph[node]){
                int edgeW = it.second;
                int adjNode = it.first;
                
                if(time + edgeW < dist[adjNode]){
                    dist[adjNode] = time + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans,dist[i]);
        }

        return ans;
        
    }
};
