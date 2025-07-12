class Solution {
  public:
  
    // recursion with memoization
    int fun(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(j == mat[0].size())  return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int maxi = fun(i, j + 1, mat, dp);
        if(i > 0){
            maxi = max(maxi, fun(i - 1, j + 1, mat, dp));
        }
        if(i < mat.size() - 1){
            maxi = max(maxi, fun(i + 1, j + 1, mat, dp));
        }
    
        return dp[i][j] = maxi + mat[i][j];
    }
  
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            ans = max(ans, fun(i, 0, mat, dp));
        }
        
        return ans;
    }
};