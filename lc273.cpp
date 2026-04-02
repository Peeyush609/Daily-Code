class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& coins, int skip, int m, int n, vector<vector<vector<int>>>& dp){
        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && skip > 0) return 0;
            return coins[i][j];
        }
        if(i >= m || j >= n){
            return -1e9;
        }

        if(dp[i][j][skip] != INT_MIN){
            return dp[i][j][skip];
        }

        int right = -1e9;
        int down = -1e9;
        int v = coins[i][j];
        down = max(down, v + solve(i + 1, j, coins, skip, m, n, dp));
        right = max(right, v + solve(i, j + 1, coins, skip, m, n, dp));

        if(skip > 0 && v < 0){
            down = max(down, solve(i + 1, j, coins, skip - 1, m, n, dp));
            right = max(right, solve(i, j + 1, coins, skip - 1, m, n, dp));
        } 

        return dp[i][j][skip] = max(right, down);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        int ans = INT_MIN;  
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(0, 0, coins, 2, m, n, dp);
    }
};