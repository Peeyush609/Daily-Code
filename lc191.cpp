class Solution {
public:

    bool check(int i, int j, vector<vector<int>>& grid, int row, int col){
        // check all the conditions 

        unordered_set<int> ss;
        // 1. no number should be > 9
        for(int r = i; r < i + 3; r++){
            for(int c = j; c < j + 3; c++){
                if(grid[r][c] > 9 || grid[r][c] == 0)  return false;
                ss.insert(grid[r][c]);
            }
        }
        
        // 2. all no. should be distinct
        if(ss.size() != 9)  return false;

        // 3. each row column and diagonal have same sum

        // find the sum of one thing and then check with others
        int sum = 0;
        for(int r = i; r < i + 3; r++){
            sum += grid[r][j];
        }

        // check for all row sums
        for(int r = i; r < i + 3; r++){
            int row_sum = 0;
            for(int c = j; c < j + 3; c++){
                row_sum += grid[r][c];
            }
            if(row_sum != sum)  return false;
        }

        // check for all column sums
        for (int c = j; c < j + 3; c++) {
            int col_sum = 0;
            for (int r = i; r < i + 3; r++) {
                col_sum += grid[r][c];
            }
            if (col_sum != sum) return false;
        }


        // check for all diagonal sums
        int d1_sum = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        if(d1_sum != sum)   return false;
        int d2_sum = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
        if(d2_sum != sum)   return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int i = 0; i <= row - 3; i++){
            for(int j = 0; j <= col - 3; j++){
                // now each cell that will be selected is the top left most cell of the 3*3 square
                if(check(i, j, grid, row, col))   ans++;
            }
        }

        return ans;
    }
};