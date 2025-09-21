class Solution {
  public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
    
        // memo[i][j] stores the width of consecutive 1's
        // ending at position (i, j).
        vector<vector<int>> memo(n, vector<int>(m, 0));
        int ans = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) continue;
    
                // Compute width of 1's at (i, j).
                memo[i][j] = (j == 0) ? 1 : memo[i][j - 1] + 1;
    
                int width = memo[i][j];
    
                // Traverse upwards row by row,
                // update minimum width and calculate area.
                for (int k = i; k >= 0; k--) {
                    width = min(width, memo[k][j]);
                    int area = width * (i - k + 1);
                    ans = max(ans, area);
                }
            }
        }
    
        return ans;
    }
};