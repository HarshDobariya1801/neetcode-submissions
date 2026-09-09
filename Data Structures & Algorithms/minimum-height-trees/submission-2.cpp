class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        vector<int> indegree(n,0), ans(n);

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
            }
        }

        while(!q.empty()){
            int s = q.size();
            ans.clear();

            for(int i = 0; i < s; i++){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto it : graph[node]){
                    indegree[it]--;
                    if(indegree[it] == 1){
                        q.push(it);
                    }
                }

            }
            
        }

        if(n == 1)  return {0};

        return ans;
        
    }
};