class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int t = 0;
        for(int i = x; i < x + k/2; i++){
            for(int j = y; j < y + k; j++){
                int a = grid[x+k-1-t][j];
                grid[x+k-t-1][j] = grid[i][j];
                grid[i][j] = a;
            }
            t++;
        }

        return grid;
    }
};