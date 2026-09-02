class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        map<int,int> m;

        for(int i = 0; i < n; i ++){
            m[nums[i]] = i;
        }

        for(int i = 0; i < n; i++){
            if(m.find(target - nums[i]) != m.end() && i != m[target-nums[i]])
                return {i, m[target-nums[i]]};
        }

        return {};
        
    }
};
