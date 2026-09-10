class Solution {
private:
    int getPivot(vector<int> &nums){
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while(left < right){
            mid = left + ((right - left)/2);

            if(nums[mid] >= nums[0]){
                left = mid + 1;
            }else right = mid;
        }

        return left;
    }

    int binarySearch(int left,int right, vector<int> &nums, int target){
        int mid;

        while(left <= right){
            mid = left + ((right - left)/2);
            if(nums[mid] == target) return mid;

            if(target > nums[mid]){
                left = mid + 1;
            }else right = mid - 1;
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int ind = getPivot(nums);

        if(nums[ind] == target) return ind;

        if(target >= nums[ind] and target <= nums[n-1]){
           return binarySearch(ind,n-1,nums,target);
        }else{
           return binarySearch(0,ind - 1, nums, target);
        }
        
    }
};
