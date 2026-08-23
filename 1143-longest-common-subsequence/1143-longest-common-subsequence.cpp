class Solution {
public:

    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, string& s1, string& s2) {

        if(i == m || j == n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int len = 0;

        // Take if characters match
        if(s1[i] == s2[j]) {
            len = 1 + solve(i + 1, j + 1, s1, s2);
        }

        // Skip s1[i]
        len = max(len, solve(i + 1, j, s1, s2));

        // Skip s2[j]
        len = max(len, solve(i, j + 1, s1, s2));

        return dp[i][j] = len;
    }

    int longestCommonSubsequence(string text1, string text2) {

        m = text1.size();
        n = text2.size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, text1, text2);
    }
};