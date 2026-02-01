class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        // the ans is sum of 1st number  + 2 min number out of rest numbers
        int first = nums[0];
        sort(nums.begin(), nums.end());
        if(first != nums[0] && first != nums[1]){
            return (nums[0] + nums[1] + first);
        }
        else if(first == nums[0]){
            return first + nums[1] + nums[2];
        }
        else{
            return first + nums[0] + nums[2];
        }

        return -1;
    }
};