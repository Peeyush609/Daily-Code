class Solution {
  public:
    int solve(vector<int>& arr, int n, int i, int stock, vector<vector<int>>& dp){
        if(i >= n){
            return 0;
        }
        
        if(dp[i][stock] != -1){
            return dp[i][stock];
        }
        
        int sell = INT_MIN;
        int buy = INT_MIN;
        // if stock then sell else buy or skip this chance
        if(stock){
            sell = arr[i] + solve(arr, n, i + 2, 0, dp);
        }
        else{
            buy = solve(arr, n, i + 1, 1, dp) - arr[i];
        }
        int skip = solve(arr, n, i + 1, stock, dp);
        
        return dp[i][stock] = max(max(buy, sell), skip);
    }  
    
    int maxProfit(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(arr, n, 0, 0, dp);
    }
};