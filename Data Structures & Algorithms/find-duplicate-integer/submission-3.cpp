class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }

        return 0;

        // T.C - O(n) and S.C - O(n)
        // unordered_map<int,bool> m;

        // for(int i = 0; i < n; i++){
        //     if(m[nums[i]] == true){
        //         return nums[i];
        //     }

        //     m[nums[i]] = true;
        // }

        // return 0;
        
    }
};
