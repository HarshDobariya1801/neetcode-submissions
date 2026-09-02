class DSU{

    public:
        vector<int> parent,rank,size;

        DSU(int n){
            parent.resize(n,0);
            rank.resize(n+1,0);
            for(int i = 0; i < n; i++){
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

            if(ulp_v == ulp_u) return;

            if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        //int n = edges.size();

        // vector<vector<int>> graph(n);

        // for(int i = 0; i < n; i++){
        //     for(auto it : edges[i]){
        //         int u = it[0];
        //         int v = it[1];

        //         graph[u].push_back(v);
        //         graph[v].push_back(u);
        //     }
        // }

        DSU ds(n);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            ds.unionByRank(u,v);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(ds.findUPar(i) == i) ans++;

        }

        return ans;

    }
};
