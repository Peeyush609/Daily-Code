class Solution {
public:

    bool check(int i2, int j2, vector<vector<int>>& mat, int threshold, int len, int m, int n){

        if(i2 + len > m || j2 + len > n)  return false;

        int sum = 0;
        for(int i = i2; i < i2 + len; i++){
            for(int j = j2; j < j2 + len; j++){
                sum += mat[i][j];
                if(sum > threshold) return false;
            }
        }

        return true;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;

        // long long sum = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0 ; j < n; j++){
                for(int len = ans + 1; len <= min(m, n); len++){
                    if (check(i, j, mat, threshold, len, m, n)){
                        ans = len;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        return ans;
    }
};