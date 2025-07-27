class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        unordered_set<int> rows;
        unordered_set<int> cols;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(int r : rows){
            for(int c = 0; c < m; c++){
                mat[r][c] = 0;
            }
        }
        
        for(int c : cols){
            for(int r = 0; r < n; r++){
                mat[r][c] = 0;
            }
        }
        
    }
};