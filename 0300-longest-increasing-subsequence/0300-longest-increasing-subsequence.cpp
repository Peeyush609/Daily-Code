class Solution {
public:
    int solve(int i, vector<int>& nums, int n, int last, vector<vector<int>>& dp){
        if(i == n)  return 0;

        if(dp[i][last] != -1)   return dp[i][last];

        int take = 0, skip = 0;
        skip = solve(i + 1, nums, n, last, dp);

        if(nums[i] > nums[last]){
            take = 1 + solve(i + 1, nums, n, i, dp);
        }

        return dp[i][last] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 1;
        for(int i = 0; i < n; i++){
            ans = max(ans, 1 + solve(i + 1, nums, n, i, dp));
        }
        return ans;
    }
};