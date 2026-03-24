class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int mod = 12345;
        vector<vector<int>> ans(n, vector<int>(m, 0));

        vector<long long> prefix(m*n, 0);
        vector<long long> suffix(m*n, 0);

        long long pre = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int ind = i*m + j;

                prefix[ind] = pre;
                pre = (pre*grid[i][j])% mod;
            }
        }

        long long suff = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int ind = i*m + j;

                suffix[ind] = suff;
                suff = (suff*grid[i][j])% mod;
            }
        }   

        for(long long x: prefix)  cout<<x<<" ";
        cout<<endl;
        for(long long x: suffix)  cout<<x<<" ";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int ind = i*m + j;
                ans[i][j] = (long long)(prefix[ind]*suffix[ind]) % mod;
            }
        }

        return ans;
    }
};