class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

       // vector<pair<int,int>> v(n + 1, {0,0});

       vector<int> indegree(n+1,0);

        for(auto it : trust){
            int u = it[0];
            int v = it[1];
            indegree[v]++;
        }

        // for(int i = 0; i <= n; i++){
        //     cout << i << " " << indegree[i] << endl;
        // }

        for(int i = 0; i <= n; i++){
            if(indegree[i] != 0 and indegree[i] != n - 1) return -1;
            if(indegree[i] == n - 1) return i;
        }

        return -1;
        
    }
};