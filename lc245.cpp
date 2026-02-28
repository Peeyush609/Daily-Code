class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long long ans = 0;
        int len = 0;

        for(int i = 1; i <= n; i++) {

            // If i is power of 2 → bit length increases
            if((i & (i - 1)) == 0) {
                len++;
            }

            ans = ((ans << len) % mod + i) % mod;
        }

        return ans;
    }
};