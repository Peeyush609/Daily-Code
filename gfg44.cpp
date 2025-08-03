class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> diff(n, vector<int>(m, 0));
        
        for(auto it: opr){
            int v = it[0];
            int r1 = it[1];
            int c1 = it[2];
            int r2 = it[3];
            int c2 = it[4];
            
            diff[r1][c1] += v;
            if(c2 + 1 < m)    diff[r1][c2 + 1] -= v;
            if(r2 + 1 < n)    diff[r2 + 1][c1] -= v;
            if(r2 + 1 < n && c2 + 1 < m)    diff[r2 + 1][c2 + 1] += v;
        }
        
        // row wise prefix sum
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                diff[i][j] += diff[i][j - 1];
            }
        }
        
        // column wise prefix sum
        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){
                diff[i][j] += diff[i-1][j];
            }
        }
        
        // now apply these diff
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[i][j] += diff[i][j];
            }
        }
        
        return mat;
    }
};