class Solution {
public:

    // return the first occ of the element target else -1
    int lower_bound(int target, vector<int>& nums){
        int n = nums.size();
        int ind = -1;

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                ind = mid;
            }
            
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ind;
    }

    // return the last occ of the element target else -1
    int upper_bound(int target, vector<int>& nums){
        int n = nums.size();
        int ind = -1;

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                ind = mid;
            }
            
            if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ind;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(target, nums), upper_bound(target, nums)};
    }
};