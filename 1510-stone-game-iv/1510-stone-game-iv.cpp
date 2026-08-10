class Solution {
public:
    bool solve(int n, vector<bool>& dp){
        if(n == 0)  return false;

        if(dp[n] == true)   return true;

        for(int i = sqrt(n); i >= 1; i--){
            if(!solve(n - i*i, dp)){
                return dp[n] = true;;
            }
        }

        // will never reach
        return false;
    }

    bool winnerSquareGame(int n) {
        // find largest square no. smallesr than or equal to n and subtract that from n
        vector<bool> dp(n + 1, false);        
        return solve(n, dp);
    }
};