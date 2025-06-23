class Solution {
public:
    // Convert number to base-k string
    string toBaseK(long long x, int k) {
        string res;
        while (x > 0) {
            res += (x % k) + '0';
            x /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l, --r;
        }
        return true;
    }

    // Generate palindromic numbers in decimal
    long long createPalindrome(int num, bool odd) {
        long long res = num;
        if (odd) num /= 10;  // Drop the middle digit
        while (num > 0) {
            res = res * 10 + (num % 10);
            num /= 10;
        }
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        for (int length = 1; count < n; ++length) {
            // Odd-length palindromes
            for (int i = pow(10, length - 1); count < n && i < pow(10, length); ++i) {
                long long pal = createPalindrome(i, true);
                string baseK = toBaseK(pal, k);
                if (isPalindrome(baseK)) {
                    sum += pal;
                    ++count;
                }
            }

            // Even-length palindromes
            for (int i = pow(10, length - 1); count < n && i < pow(10, length); ++i) {
                long long pal = createPalindrome(i, false);
                string baseK = toBaseK(pal, k);
                if (isPalindrome(baseK)) {
                    sum += pal;
                    ++count;
                }
            }
        }

        return sum;
    }
};
