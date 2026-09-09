class DSU{
    public:
        vector<int> parent,rank;

        DSU(int n){
            parent.resize(n+1,0);
            rank.resize(n+1,0);

            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<pair<int,pair<int,int>>> graph;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int distance = abs(points[i][0]-points[j][0]) 
                + abs(points[i][1]-points[j][1]);
                graph.push_back({distance, {i,j}});
            }
        }

        DSU ds(n);
    
        sort(graph.begin(),graph.end());

        int ans = 0;

        for(auto it : graph){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUPar(u) != ds.findUPar(v)){
                ans += wt;
                ds.unionByRank(u,v);
            }

        
        }

        return ans;
    }
};
