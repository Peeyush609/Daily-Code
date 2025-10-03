class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        if (n <= 2 || m <= 2) return 0; // No water can be trapped in a grid smaller than 3x3.

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Min-heap to store the height and coordinates of blocks.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minheap;

        // Add all boundary cells to the heap and mark them as visited.
        for (int row = 0; row < n; row++) {
            for (int col : {0, m - 1}) {
                minheap.push({heightMap[row][col], {row, col}});
                visited[row][col] = 1;
            }
        }

        for (int col = 0; col < m; col++) {
            for (int row : {0, n - 1}) {
                minheap.push({heightMap[row][col], {row, col}});
                visited[row][col] = 1;
            }
        }

        // Directions for traversing neighbors (up, right, down, left).
        vector<int> ver = {1, 0, -1, 0};
        vector<int> hor = {0, 1, 0, -1};

        int water = 0;

        while (!minheap.empty()) {
            auto [height, coord] = minheap.top();
            int x = coord.first;
            int y = coord.second;
            minheap.pop();

            // Visit all neighbors of the current cell.
            for (int i = 0; i < 4; i++) {
                int xx = x + ver[i];
                int yy = y + hor[i];

                // Check if the neighbor is within bounds and not visited.
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy]) {
                    // Calculate trapped water for the neighbor.
                    water += max(0, height - heightMap[xx][yy]);

                    // Update the neighbor's height to the max of its height or the current height.
                    minheap.push({max(height, heightMap[xx][yy]), {xx, yy}});

                    // Mark the neighbor as visited.
                    visited[xx][yy] = 1;
                }
            }
        }

        return water;
    }
};
