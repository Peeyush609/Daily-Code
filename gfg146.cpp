class Solution {
  public:
    int findMaxSum(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if(i == arr.size() + 1) return 0;
        
        // if this subproblem is already solved
        // return the stored value
        if(dp[i][j] != -1) return dp[i][j];
        
        // i - current index(1-based index)
        // j - last chosen index(1-based index)
        // if j = 0, no element is chosen
        if(j == 0 || arr[i-1] > arr[j-1]) {
            return dp[i][j] = max(arr[i-1] + findMaxSum(arr, i+1, i, dp),
                                  findMaxSum(arr, i+1, j, dp));
        }
        // if current element <= last chosen element
        // we can't chose current element
        else return dp[i][j] = findMaxSum(arr, i+1, j, dp);
    }
    
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return findMaxSum(arr, 1, 0, dp);
    }
};