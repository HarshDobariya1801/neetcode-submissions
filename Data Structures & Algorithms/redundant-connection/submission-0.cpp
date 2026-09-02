class DSU{
    public:
        vector<int> parent, rank, size;

        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            size.resize(n+1,1);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;

            return parent[node] =  findUPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_v = parent[v];
            int ulp_u = parent[u];

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

        void unionBySize(int u, int v){
            int ulp_v = parent[v];
            int ulp_u = parent[u];

            if(ulp_v == ulp_u) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        DSU ds(n);

        int a,b;

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            if(ds.findUPar(u) == ds.findUPar(v)){
                a = u;
                b = v;
            }

            ds.unionByRank(u,v);
           //ds.unionBySize(u,v);

            
        }

        return {a,b};
        
    }
};
