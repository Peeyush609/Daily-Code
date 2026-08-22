class Solution {
public:

    int solve(int i, vector<int>& nums, int n, vector<int>& dp){
        if(i >= n)  return 0;

        if(dp[i] != -1)  return dp[i];
        int ans = 0;

        // take
        ans = max(ans, nums[i] + solve(i + 2, nums, n, dp));
        
        // skip
        ans = max(ans, solve(i + 1, nums, n, dp));

        return dp[i] = ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];

        vector<int> dp(n, -1);
        int ans = solve(0, nums, n - 1, dp);
        fill(dp.begin(), dp.end(), -1);
        return max(ans, solve(1, nums, n, dp));
    }
};