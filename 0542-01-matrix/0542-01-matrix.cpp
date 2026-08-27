class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1)); // Distance matrix
        queue<pair<int, int>> q;

        // Initialize queue with all '0' cells and set their distances to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0; // Distance for '0' cells is 0
                }
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // Check bounds and ensure the cell hasn't been visited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1; // Update distance
                    q.push({nx, ny});             // Push the cell into the queue
                }
            }
        }

        return dist;
    }
};