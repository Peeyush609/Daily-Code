class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        vector<int> row_Sum(m, 0);
        vector<int> col_Sum(n, 0);

        for(int i = 0; i < m; i++){
            int s = 0;
            for(int j = 0; j < n; j++){
                s += mat[i][j];
            }
            row_Sum[i] = s;
        }

        for(int j = 0; j < n; j++){
            int s = 0;
            for(int i = 0; i < m; i++){
                s += mat[i][j];
            }
            col_Sum[j] = s;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && (row_Sum[i] == 1 && col_Sum[j] == 1)){
                    ans++;
                }
            }
        }

        return ans;
    }
};