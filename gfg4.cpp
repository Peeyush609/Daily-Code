class Solution {
public:
    vector<int> largestSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());  // Sorting is needed

        vector<vector<int>> dp(n);  // dp[i] stores the actual subset ending at index i
        vector<int> bestSubset;

        for (int i = 0; i < n; ++i) {
            dp[i] = {nums[i]};  // Start with the number itself

            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    // If we can extend the subset ending at j
                    vector<int> candidate = dp[j];
                    candidate.push_back(nums[i]);

                    // Choose if better by length, or equal length but lexicographically greater
                    if (candidate.size() > dp[i].size() || 
                       (candidate.size() == dp[i].size() && candidate > dp[i])) {
                        dp[i] = candidate;
                    }
                }
            }

            // Update bestSubset based on max size or lexicographical order
            if (dp[i].size() > bestSubset.size() || 
               (dp[i].size() == bestSubset.size() && dp[i] > bestSubset)) {
                bestSubset = dp[i];
            }
        }

        return bestSubset;
    }
};
