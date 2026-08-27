class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int level = 1;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x >= 0 && x < m && y >= 0 && y < n &&
                    ans[x][y] > (ans[i][j] + 1)) {
                    ans[x][y] = ans[i][j] + 1;
                    q.push({x, y});
                }
            }
        }

        return ans;
    }
};