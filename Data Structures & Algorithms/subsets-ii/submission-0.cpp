class Solution {
private:
    void solve(int i, int n, vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, set<vector<int>> &st){

        if(i == n){
            st.insert(temp);
            return;
        }

        solve(i+1, n, nums, ans,temp,st);

        temp.push_back(nums[i]);
        solve(i+1, n, nums, ans,temp,st);
        temp.pop_back();

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(),nums.end());
        set<vector<int>> st;

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0,n,nums,ans,temp,st);

        for(auto it:st) ans.push_back(it);

        return ans;
        
    }
};
