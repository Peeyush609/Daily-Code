class Solution {
public:
    int fun(vector<int>& nums, int n){

        if(n == 1)  return nums[0];

        for(int i = 0; i < n-1; i++){
            nums[i] = (nums[i] + nums[i + 1])%10;
        }
        return fun(nums,n - 1);
    }

    int triangularSum(vector<int>& nums) {
        return fun(nums, nums.size());
    }
};