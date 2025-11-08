int numberOfPath(vector<vector<int>>& mat, int k) {
    int n = mat.size(), m = mat[0].size();
    
     // Use only two 2D arrays for space optimization
    vector<vector<int>> prev(m, vector<int>(k + 1, 0));
    vector<vector<int>> curr(m, vector<int>(k + 1, 0));

    // Build DP table iteratively
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int sum = 0; sum <= k; sum++) {
                
                // Base case
                if (i == 0 && j == 0) {
                    
                    // Only one way if sum matches cell value
                    curr[j][sum] = (sum == mat[0][0]);
                    continue;
                }

                curr[j][sum] = 0;

                if (sum - mat[i][j] >= 0) {
                    
                    // from top
                    if (i > 0) curr[j][sum] += prev[j][sum - mat[i][j]];
                   
                    // from left
                    if (j > 0) curr[j][sum] += curr[j - 1][sum - mat[i][j]];
                }
            }
        }
        
        // Move current row to previous row
        prev = curr;
    }

    // Total ways to reach bottom-right with sum = k
    return prev[m - 1][k];
}