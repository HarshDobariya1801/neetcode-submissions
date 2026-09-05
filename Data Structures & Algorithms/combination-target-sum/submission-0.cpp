class Solution {
private:
    void solve(int i, int n, vector<int> &nums, int sum,int target,vector<vector<int>> &ans,vector<int> &temp){

        if(i == n){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }
        if(sum > target) return;

        // pick
        if(nums[i] <= target){
            sum += nums[i];
            temp.push_back(nums[i]);
            solve(i,n,nums,sum,target, ans,temp);
            sum = sum - nums[i];
            temp.pop_back();
        }
        

        solve(i+1,n,nums,sum,target,ans,temp);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0,n,nums,0,target,ans,temp);

        return ans;
        
    }
};
