class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,bool> m;

        for(int i = 0; i < n; i++){
            if(m[nums[i]] == true){
                return nums[i];
            }

            m[nums[i]] = true;
        }

        return 0;
        
    }
};
