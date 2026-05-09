class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // both even 

        int i = 0, j = 0;
        while(i < m/2 && j < n/2){
            
            int count = 2*(m-2*i) + 2*(n-2*j) - 4;
            int rot = k % (count);
            while(rot--){

                int x = i, y = j;
                // down
                int last = -1;
                while(x < m - i - 1){
                    int curr = grid[x][y];
                    grid[x][y] = last;
                    last = curr;
                    x++;
                }
                // right
                while(y < n - j - 1){
                    int curr = grid[x][y];
                    grid[x][y] = last;
                    last = curr;
                    y++;
                }
                // up
                while(x > i){
                    int curr = grid[x][y];
                    grid[x][y] = last;
                    last = curr;
                    x--;
                }
                // left
                while(y >= j){
                    int curr = grid[x][y];
                    grid[x][y] = last;
                    last = curr;
                    y--;
                }
                // grid[i][j] = last;
            }

            i++;
            j++;
        }

        return grid;
    }
};