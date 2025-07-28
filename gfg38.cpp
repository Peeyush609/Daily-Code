class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        // max of req row sum or sol sum
        
        int maxrow_Sum = 0;
        int maxcol_Sum = 0;
        
        for(int i = 0; i < n; i++){
            int row_sum = 0;
            int col_sum = 0;
            for(int j = 0; j < n; j++){
                row_sum += mat[i][j];
                col_sum += mat[j][i];
            }
            maxcol_Sum = max(maxcol_Sum, col_sum);
            maxrow_Sum = max(maxrow_Sum, row_sum);
        }
        
        int row = 0;
        int col = 0;
        for(int i = 0; i < n; i++){
            int row_sum = 0;
            int col_sum = 0;
            for(int j = 0; j < n; j++){
                row_sum += mat[i][j];
                col_sum += mat[j][i];
            }
            row += (maxcol_Sum - col_sum);
            col += (maxrow_Sum - row_sum);
        }
        
        return max(row, col);
        
    }
};