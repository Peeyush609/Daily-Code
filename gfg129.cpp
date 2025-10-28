#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));  // stores distances
        queue<pair<int, int>> q;

        // Step 1: Push all cells with 1 into the queue and set their distance = 0
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: BFS in 4 directions
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                // Check bounds and if not already visited
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};
