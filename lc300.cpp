class Solution {
public:
    int solve(int i, int j, int k, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>& dp){
        int val = grid[i][j];
        int cost = (val > 0) ? 1 : 0;
        if(i == m - 1 && j == n - 1){
            if(k >= cost){
                return val;
            }
            else{
                return INT_MIN;
            }
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        int right = INT_MIN;
        int down  = INT_MIN;
        // right
        if(k >= cost && j < n - 1){
            right = val + solve(i, j + 1, k - cost, grid, m, n, dp);
        }
        // down
        if(k >= cost && i < m - 1){
            down = val + solve(i + 1, j, k - cost, grid, m, n, dp);
        }

        return dp[i][j][k] = max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int ans = solve(0, 0, k, grid, m, n, dp);
        return ans >= 0 ? ans : -1;
    }
};