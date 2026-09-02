class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        vector<int> indegree(numCourses,0);

        for(auto e: prerequisites){
            int u = e[0];
            int v = e[1];

            graph[v].push_back(u);
            indegree[u]++;
        }

        vector<int> vis(numCourses,0);
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: graph[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == numCourses) return true;
        return false;
    }
};
