class Solution {
public:

    int solve(int i, vector<int>& nums, int target, int n,vector<int>& dp){
        if(i == n - 1){
            return 0;
        }

        if(dp[i] != INT_MIN)    return dp[i];

        int maxi = INT_MIN;

        for(int j = i + 1; j < n; j++){
            int diff = abs(nums[j] -nums[i]);
            if(diff <= target){
                int curr = 1 + solve(j, nums, target, n, dp);
                maxi = max(maxi, curr);        
            }
        }

        return dp[i] = maxi;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        int ans = solve(0, nums, target, n, dp);

        return ans < 0 ? -1 : ans;
    }
};