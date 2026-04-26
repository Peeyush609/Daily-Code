class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

    bool dfs(int i, int j, int px, int py, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for(auto &d : dir){
            int x = i + d[0];
            int y = j + d[1];

            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() 
               && grid[x][y] == grid[i][j]){

                if(!visited[x][y]){
                    if(dfs(x, y, i, j, grid, visited)) return true;
                }
                else if(x != px || y != py){
                    // visited and not parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    if(dfs(i, j, -1, -1, grid, visited)) return true;
                }
            }
        }
        return false;
    }
};