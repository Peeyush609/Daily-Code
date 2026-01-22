class Solution {
public:

    void fun(vector<int>& nums){
        int n = nums.size();

        int ind = -1;
        int mini = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] + nums[i + 1] < mini){
                mini = nums[i] + nums[i + 1];
                ind = i;
            }
        }
        nums[ind] = mini;
        nums.erase(nums.begin() + ind + 1);
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return 0;

        // check if non decreasing
        bool inc = true;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                inc = false;
                break;
            }
        }
        if(inc) return 0;

        // apply the function and remove left most pair with min sum
        fun(nums);

        return 1 + minimumPairRemoval(nums);
    }
};