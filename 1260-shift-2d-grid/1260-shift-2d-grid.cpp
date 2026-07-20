class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n,-1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int ind = i*n + j;
                int new_ind = (ind + k) % (m * n);

                int new_i = new_ind / n;
                int new_j = new_ind % n;

                ans[new_i][new_j] = grid[i][j];
            }
        }

        return ans;
    }
};