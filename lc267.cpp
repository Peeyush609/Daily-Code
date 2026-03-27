class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;//agar k jyada hai ns se to and after n rotation wo normal ho jayega isliye farak nhi pdega

        for(int i = 0; i < m; i++){
            int shift = k;
            if(i % 2 == 1)  shift = n - k;//left shift general hai agr right krna hai to n - k left krdo 

            for(int j = 0; j < n; j++){
                int new_j = (shift + j) % n;
                if(mat[i][new_j] != mat[i][j])  return false;
            }
        }

        return true;
    }
};