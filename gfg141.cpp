class Solution {
  public:
    int chocolatePickup(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
    
        // for storing the answers for current row
        vector<vector<int>> curr(m, vector<int>(m, 0));
    
        // for storing the answers of next row
        vector<vector<int>> next(m, vector<int>(m, 0));
    
        // filling dp array in bottom up way
        for (int i1 = n - 1; i1 >= 0; i1--) {
    
            // creating a new array to fill answers
            // for current row based on next row
            curr = vector<vector<int>>(m, vector<int>(m, 0));
    
            for (int j1 = m - 1; j1 >= 0; j1--) {
                for (int j2 = m - 1; j2 >= 0; j2--) {
    
                    // base case
                    if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1) {
                        curr[m - 1][m - 1] = ((mat[n - 1][m - 1] == -1) ? -1 : mat[n - 1][m - 1]);
                        continue;
                    }
    
                    int i2 = i1 + j1 - j2;
    
                    // robot2 in an invalid row
                    if (i2 >= n || i2 < 0)
                        continue;
                    int ans = -1;
                    int dir[2][2] = {{1, 0}, {0, 1}};
                    for (auto &d1 : dir) {
                        for (auto &d2 : dir) {
                            int newRow1 = i1 + d1[0];
                            int newCol1 = j1 + d1[1];
                            int newRow2 = i2 + d2[0];
                            int newCol2 = j2 + d2[1];
    
                            // taking maximum chocolates
                            // among all possibilities
                            if (newRow1 < n && newRow2 < n && newCol1 < m && newCol2 < m &&
                                mat[newRow1][newCol1] != -1 && mat[newRow2][newCol2] != -1) {
                                if (newRow1 == i1 + 1) {
                                    ans = max(ans, next[newCol1][newCol2]);
                                }
                                else {
                                    ans = max(ans, curr[newCol1][newCol2]);
                                }
                            }
                        }
                    }
                    if (ans == -1 || mat[i1][j1] == -1 || mat[i2][j2] == -1) {
                        curr[j1][j2] = -1;
                        continue;
                    }
                    ans += mat[i1][j1];
    
                    // if both robots not in the same cell
                    if (i1 != i2 && mat[i1][j1] != -1)
                        ans += mat[i2][j2];
                    curr[j1][j2] = ans;
                }
            }
            next = curr;
        }
        // returning 0 if its not possible(negative value)
        // else maximum chocolates obtained
        return max(0, next[0][0]);
    }
};