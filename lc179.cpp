class Solution {
public:
    vector<vector<vector<long long>>> dp;    
    long long fun(vector<int>& prices, int i, int k, int transition){
        if(i == prices.size() || k == 0){
            if(transition != 0) return INT_MIN;
            return 0;
        }

        if(dp[i][k][transition] != -1){
            return dp[i][k][transition];
        }

        // tranistion =0 : nothing happened
        // tranistion =1 : bought happened
        // tranistion =2 : sold happened

        long long a = -1;
        if(transition == 0){
            long long buy = fun(prices, i + 1, k, 1) - prices[i];
            long long sell = fun(prices, i + 1, k, 2) + prices[i];
            long long skip = fun(prices, i + 1, k, 0);

            a = max({buy, sell, skip});
        }
        else if(transition == 1){
            long long sell = fun(prices, i + 1, k - 1, 0) + prices[i];
            long long skip = fun(prices, i + 1, k, 1);

            a = max({sell, skip});
        }
        else{
            long long buy = fun(prices, i + 1, k - 1, 0) - prices[i];
            long long skip = fun(prices, i + 1, k, 2);

            a = max(buy, skip);
        }

        return dp[i][k][transition] = a;
    }
    
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        dp = vector<vector<vector<long long>>>(n + 1, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));
        return fun(prices, 0, k, 0);
    }
};