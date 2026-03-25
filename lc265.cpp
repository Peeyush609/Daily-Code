class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j];
            }
        }

        long long hori = 0; //checking horizontally first
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                hori += grid[i][j];
            }

            long long rem = total - hori;
            if(rem == hori){
                return true;// possible horizontal cut solution
            } 
        }

        long long ver = 0; //checking vertically now
        for(int j = 0; j < n - 1; j++){
            for(int i = 0; i < m; i++){
                ver += grid[i][j];
            }

            long long rem = total - ver;
            if(rem == ver){
                return true;// possible vertical cut solution
            } 
        }

        return false;
    }
};