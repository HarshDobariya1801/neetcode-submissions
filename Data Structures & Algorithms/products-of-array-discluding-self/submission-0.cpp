class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        int countZero = count(nums.begin(),nums.end(),0);

        vector<int> ans(n,0);

        if(countZero > 1) return ans;

        int multi = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                multi = multi * nums[i];
            }
        }

        for(int i = 0; i < n; i++){
            if(countZero == 1){
                if(nums[i] == 0) ans[i] = multi;
            }else if(countZero == 0){
                ans[i] = multi/nums[i];
            }
        }

        return ans;

    }
};
