class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int solve(int i, int j, vector<vector<int>>& matrix){

        if(dp[i][j] != -1)  return dp[i][j];
        int curr = matrix[i][j];
        int ans = 1;
        for(auto dir: directions){
            int x = i + dir[0];
            int y = j + dir[1];

            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > curr){
                int temp = 1 + solve(x, y, matrix);
                ans = max(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        dp.resize(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, solve(i, j, matrix));
            }
        }

        return ans;
    }
};