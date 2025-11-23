class Solution {
public:
    vector<vector<int>> dp;  // Memoization table

    int fun(int i, vector<int>& nums, int mod) {
        if (i == nums.size()) 
            return (mod == 0) ? 0 : INT_MIN; // If sum % 3 == 0, return sum; otherwise, return invalid

        if (dp[i][mod] != -1) return dp[i][mod];

        // Option 1: Take nums[i]
        int take = nums[i] + fun(i + 1, nums, (mod + nums[i]) % 3);

        // Option 2: Skip nums[i]
        int skip = fun(i + 1, nums, mod);

        // Store and return the maximum valid sum
        return dp[i][mod] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(3, -1));  // Initialize memoization table
        int res = fun(0, nums, 0);  // Start recursion from index 0 with mod = 0
        return (res < 0) ? 0 : res;  // If no valid sum found, return 0
    }
};