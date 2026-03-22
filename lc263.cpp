class Solution {
public:

    vector<vector<int>> rotate_90(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n, 0));
        for(int i = 0 ;i < n; i++){
            for(int j = 0; j < n; j++){
                temp[j][n-1-i] = mat[i][j];
            }
        }
        return temp;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target)   return true;
        vector<vector<int>> a = rotate_90(mat);
        if(a == target)   return true;
        vector<vector<int>> b = rotate_90(a);
        if(b == target)   return true;
        vector<vector<int>> c = rotate_90(b);
        if(c == target)   return true;

        return false;
    }
};