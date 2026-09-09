class Solution {
private:
    int binarySearch(int left,int right,int mid,vector<int> &nums, int target){

        if(left > right) return -1;

        if(nums[mid] == target){
            return mid;
        }

        if(target > nums[mid]){
            return binarySearch(mid + 1, right,((left + right)/2), nums,target);
        }else{
            return binarySearch(left,mid - 1,((left + right)/2), nums,target);
        }


    }
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // recursion
        int left = 0;
        int right = n - 1;
        int mid = (left + right)/2;
        return binarySearch(left,right,mid,nums,target);

        // iterative 

        // int left = 0;
        // int right = n - 1;

        // int mid;

        // while(left <= right){
        //     mid = (left + right)/2;

        //     if(nums[mid] == target) return mid;

        //     if(nums[mid] < target){
        //         left = mid + 1;
        //     }else{
        //         right = mid - 1;
        //     }
        // }

        // return -1;

        
    }
};
