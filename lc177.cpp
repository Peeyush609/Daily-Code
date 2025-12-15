class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size();

        int prev = prices[0];
        long long last = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] == prev - 1){
                ans += last + 1;
                last++;
            }
            else{
                last = 0;
            }
            prev = prices[i];
        }
        return ans;
    }
};