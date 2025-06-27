/*
Mobile numeric keypad

There is a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly above, below, to the left, or to the right of it. For example, if you press 5, then pressing 2, 4, 6, or 8 is allowed. However, diagonal movements and pressing the bottom row corner buttons (* and #) are not allowed.


Given an integer n, determine how many unique sequences of length n can be formed by pressing buttons on the keypad, starting from any digit.

Examples :

Input: n = 1
Output: 10
Explanation: Possible 1-digit numbers follow keypad moves - From 0 → 0, 1 → 1, 2 → 2 and so on, total 10 valid combinations are possible.
Input: n = 2
Output: 36
Explanation: Possible 2-digit numbers follow keypad moves -
From 0 → 00, 08 (2), 
From 1 → 11, 12, 14 (3),
From 3 → 33, 32, 36 (3), and so on,
total 36 valid combinations are possible.
Constraints:
1 ≤ n ≤ 15


*/

class Solution {
  public:
    
    unordered_map<int, vector<int>> adj;
    
    int fun(int i, int n, vector<vector<int>>& dp){
        if(n == 0)  return 1;
        
        if(dp[i][n] != -1)  return dp[i][n];
        
        // now either take someone from adj or tske yourself again
        int ans = 0;
        
        // press itself again
        ans += fun(i, n - 1, dp);
        
        // choose form adjacent possible
        for(int x: adj[i]){
            ans += fun(x, n - 1, dp);
        }
        
        return dp[i][n] = ans;
    }
  
    int getCount(int n) {
        // code here
        
        adj[1] = {2, 4};
        adj[2] = {1, 3, 5};
        adj[3] = {2, 6};
        adj[4] = {1, 5, 7};
        adj[5] = {2, 4, 6, 8};
        adj[6] = {3, 5, 9};
        adj[7] = {8, 4};
        adj[8] = {0,7,5,9};
        adj[9] = {6,8};
        adj[0] = {8};
            
        int count = 0;
        for(int i = 0; i <= 9; i++){
            vector<vector<int>> dp(10, vector<int>(n, -1));
            count += fun(i, n - 1, dp);
        }
        
        return count;
    }
};