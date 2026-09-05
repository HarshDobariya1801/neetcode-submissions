class Solution {
private:
    void solve(int i, int n, vector<vector<int>> &ans, vector<int> &nums){

        if(i >= n){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < n; j++){
            swap(nums[i],nums[j]);
            solve(i+1,n,ans,nums);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;
    
        solve(0,n,ans,nums);
        
        return ans;
        
    }
};
