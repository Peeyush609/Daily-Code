class Solution {
public:
    int countOnes(long long n) {
        int count = 0;
        while (n) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int i = 1; i <= 60; i++) {
            long long val = (long long)num1 - (long long)i * num2;
            if (val < 0) continue;   // must be non-negative
            int ones = countOnes(val);
            if (ones <= i && i <= val) {
                return i;
            }
        }
        return -1;
    }
};
