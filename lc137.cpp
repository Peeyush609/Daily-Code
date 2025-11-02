class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid
        vector<vector<int>> matrix(m, vector<int>(n, 1)); // 1: empty space
        
        // Mark walls by 2
        for (vector<int> v : walls) {
            matrix[v[0]][v[1]] = 2; 
        }

        // Mark guards by 3
        for (vector<int> v : guards) {
            matrix[v[0]][v[1]] = 3;
        }

        // Mark guarded cells
        for (vector<int> v  : guards) {
            int x = v[0], y = v[1];

            // Row to the right
            for (int i = y + 1; i < n && matrix[x][i] != 2 && matrix[x][i] != 3; i++) {
                matrix[x][i] = 4;
            }

            // Row to the left
            for (int i = y - 1; i >= 0 && matrix[x][i] != 2 && matrix[x][i] != 3; i--) {
                matrix[x][i] = 4;
            }

            // Column down
            for (int i = x + 1; i < m && matrix[i][y] != 2 && matrix[i][y] != 3; i++) {
                matrix[i][y] = 4;
            }

            // Column up
            for (int i = x - 1; i >= 0 && matrix[i][y] != 2 && matrix[i][y] != 3; i--) {
                matrix[i][y] = 4;
            }
        }

        // Count unguarded cells
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) ans++;
            }
        }

        return ans;
    }
};
