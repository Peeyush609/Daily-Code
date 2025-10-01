class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        int empty = numBottles;
        int left = 0;
        while(empty / numExchange > 0){
            int n = empty/numExchange;
            empty -= numExchange*n;
            ans += n;
            empty += n;
        } 

        return ans;
    }
};