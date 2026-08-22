class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& coins, int amount){
        if(amount == 0) return 0;

        if(dp[amount] != -1)    return dp[amount];

        int ans = INT_MAX;
        for(int coin: coins){
            if(amount >= coin){
                int curr = solve(coins, amount - coin);
                if(curr != INT_MAX){
                    ans = min(ans, 1 + curr);
                }
            }
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        dp.resize(amount + 1, -1);
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};