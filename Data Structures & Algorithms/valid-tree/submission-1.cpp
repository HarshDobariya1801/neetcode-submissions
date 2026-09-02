class DSU{
    public:
        vector<int> parent,rank;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u,int v){
            int ulp_u = parent[u];
            int ulp_v = parent[v];

            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        DSU ds(n);

        for(auto e: edges){
            int u = e[0];
            int v = e[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                return false;
            }

            ds.unionByRank(u,v);
        }

        int multiComponent = 0;
        for(int i = 0; i < n; i++){
            if(ds.findUPar(i) == i){ 
                multiComponent++;
            }

        }

        if(multiComponent > 1) return false;

        return true;

    }
};
