class Solution {
public:
    int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int LCM(int a, int b) {
        return (long long)a * (b / GCD(a, b));  // Prevents overflow
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;  // Changed to long long
            int lcm = 1;
            int gcd = nums[i];

            for (int j = i; j < n; j++) {
                if (prod > LLONG_MAX / nums[j]) break;  // Prevent overflow
                prod *= nums[j];

                lcm = LCM(lcm, nums[j]);
                gcd = GCD(gcd, nums[j]);

                if (prod == (long long)lcm * gcd) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};
