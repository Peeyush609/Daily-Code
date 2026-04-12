class Solution {
public:

    int dist(int f, int c){
        if(f == 26) return 0; // '&' mapped to 26

        int x1 = f / 6, y1 = f % 6;
        int x2 = c / 6, y2 = c % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int i, int f1, int f2, string &word, vector<vector<vector<int>>>& dp){
        if(i == word.size()) return 0;

        if(dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        // use finger 1
        int one = dist(f1, curr) + solve(i + 1, curr, f2, word, dp);

        // use finger 2
        int two = dist(f2, curr) + solve(i + 1, f1, curr, word, dp);

        return dp[i][f1][f2] = min(one, two);
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));

        return solve(0, 26, 26, word, dp); // both fingers unused
    }
};