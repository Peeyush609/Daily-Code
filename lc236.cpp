class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int zeroes = 0, ones = 0;
        int i = 0;
        while (i < n) {
            zeroes = 0;
            while (i < n && s[i] == '0') {
                if (ones > 0) {
                    ans++;
                    ones--;
                }
                zeroes++;
                i++;
            }
            ones = 0;
            while (i < n && s[i] == '1') {
                if (zeroes > 0) {
                    ans++;
                    zeroes--;
                }
                ones++;
                i++;
            }
        }

        return ans;
    }
};