class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int max_sum = INT_MIN;

        int prefix_sum = 0;
        int min_sum = 0;
        for(int num : nums){
            prefix_sum += num;

            max_sum = max(max_sum, prefix_sum - min_sum);
            min_sum = min(min_sum, prefix_sum);
        }
        
        
        return max_sum;
    }
};