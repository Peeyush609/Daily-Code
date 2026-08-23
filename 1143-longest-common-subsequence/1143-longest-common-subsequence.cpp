class Solution {
public:
    // tabulation approach

    int longestCommonSubsequence(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int len = 0;

                // Take if characters match
                if (s1[i] == s2[j]) {
                    len = 1 + dp[i + 1][j + 1];
                }

                // Skip s1[i]
                len = max(len, dp[i + 1][j]);

                // Skip s2[j]
                len = max(len, dp[i][j + 1]);

                dp[i][j] = len;
            }
        }

        return dp[0][0];
    }
};