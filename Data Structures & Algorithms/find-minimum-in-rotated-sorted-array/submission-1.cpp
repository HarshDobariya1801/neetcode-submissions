class Solution {
public:
    int findMin(vector<int> &nums) {

        int n = nums.size();

        int left = 0;
        int right = n - 1;
        int mid;

        if(nums[0] < nums[n-1]){
            return nums[0];
        }else{

            while(left < right){
                mid = left + ((right - left)/2);

                if(nums[mid] >= nums[0]){
                    left = mid + 1;
                }else right = mid;
            }

            return nums[left];
        }
        
    }
};
