class Solution {
private:
    void solve(int i,int n, vector<int> &a, int target, vector<int> &temp, vector<vector<int>> &ans, set<vector<int>> &st){

       // if(i >= n) return;

        
            if(target == 0){
                //sort(temp.begin(),temp.end());
                st.insert(temp);
                return;
            }

        //pick
        for(int ind = i; ind < n; ind++){
           if(ind > i and a[ind] == a[ind-1]) continue;
            
            if(a[ind] <= target){
                temp.push_back(a[ind]);
                solve(ind+1,n,a,target-a[ind],temp,ans,st);
                temp.pop_back();
            }
        }
        
    //    solve(i+1,n,a,target,temp,ans,st);

    //     if(a[i] <= target){
    //         temp.push_back(a[i]);
    //         solve(i + 1, n,a, target- a[i],temp,ans,st);
    //         temp.pop_back();
    //     }


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int n = candidates.size();

        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> st;

       sort(candidates.begin(),candidates.end());

        solve(0,n,candidates,target,temp,ans,st);

        for(auto it : st){
            ans.push_back(it);
        }

        return ans;

        
    }
};
