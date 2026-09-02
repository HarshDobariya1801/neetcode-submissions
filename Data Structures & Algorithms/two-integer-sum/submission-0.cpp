class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        int ans1, ans2;

        map<int,int> m;

        for(int i = 0; i < n; i++){
            m[nums[i]] = i;
        }

        for(int i = 0; i < n; i++){

            if(m.find(target-nums[i]) != m.end() and i != m[target-nums[i]]){

                ans1 = i;
                ans2 = m[target-nums[i]];
                break;
            }
        }

        if(ans1 >= ans2) return {ans2,ans1};
        else return {ans1,ans2};

        
        
    }
};
