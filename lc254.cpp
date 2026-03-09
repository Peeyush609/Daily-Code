class Solution {
public:
    int mod = 1e9 + 7;
    int dp[201][201][201][2];

    int solve(int z, int o, int cnt, int last, int limit){
        if(z == 0 && o == 0) return 1;

        if(dp[z][o][cnt][last] != -1)
            return dp[z][o][cnt][last];

        long long ans = 0;

        // place zero
        if(z > 0){
            if(last == 0){
                if(cnt + 1 <= limit)
                    ans += solve(z-1, o, cnt+1, 0, limit);
            } 
            else{
                ans += solve(z-1, o, 1, 0, limit);
            }
        }

        // place one
        if(o > 0){
            if(last == 1){
                if(cnt + 1 <= limit)
                    ans += solve(z, o-1, cnt+1, 1, limit);
            }
            else{
                ans += solve(z, o-1, 1, 1, limit);
            }
        }

        return dp[z][o][cnt][last] = ans % mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        if(zero > 0)
            ans += solve(zero-1, one, 1, 0, limit);

        if(one > 0)
            ans += solve(zero, one-1, 1, 1, limit);

        return ans % mod;
    }
};