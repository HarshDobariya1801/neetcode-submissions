class Solution {
private:
    void solve(int i,int n, vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp){

        if(i >= n){
            ans.push_back(temp);
            return;
        }

        // not pick
        solve(i+1,n,nums,ans,temp);

        temp.push_back(nums[i]);
        solve(i+1,n,nums,ans,temp);
        temp.pop_back();
        

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0,n,nums,ans,temp);

        return ans;
        
    }
};
