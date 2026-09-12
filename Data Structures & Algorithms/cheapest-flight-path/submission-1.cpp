class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> graph(n);

        for(auto e : flights){
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            graph[u].push_back({v,cost});
        }

        vector<int> dist(n,1e9);
        // {stop, {node,dist}};
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0, {src,0}});
        dist[src] = 0;


        while(!pq.empty()){
            int stops = pq.front().first;
            int node = pq.front().second.first;
            int cost = pq.front().second.second;
            pq.pop();
            if(stops > k) continue;
            
            for(auto it : graph[node]){
                int adjNode = it.first;
                int edw = it.second;

                if(cost + edw < dist[adjNode] and stops <= k){
                    dist[adjNode] = cost + edw;
                    pq.push({stops+1, {adjNode, cost + edw}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;

        return dist[dst];
        
    }
};
