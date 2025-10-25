class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        // 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
        ans += (n / 7)*28;
        int time = (n/7);
        ans += (time * (time - 1)/2)*7;

        int rem = n%7;
        int mon = 1 + time;
        while(rem--){
            ans += mon;
            mon++;
        }


        return ans;
    }
};