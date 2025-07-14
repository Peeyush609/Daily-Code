/*

Cutting Binary String
Difficulty: MediumAccuracy: 49.71%Submissions: 35K+Points: 4
You are given a binary string s consisting only of characters '0' and '1'. Your task is to split this string into the minimum number of non-empty substrings such that:

Each substring represents a power of 5 in decimal (e.g., 1, 5, 25, 125, ...).
No substring should have leading zeros.
Return the minimum number of such pieces the string can be divided into.
Note: If it is not possible to split the string in this way, return -1.

Examples:

Input: s = "101101101"
Output: 3
Explanation: The string can be split into three substrings: "101", "101", and "101", each of which is a power of 5 with no leading zeros.
Input: s = "1111101"
Output: 1
Explanation: The string can be split into one binary string "1111101" which is 125 in decimal and a power of 5 with no leading zeros.


Input: s = "00000"
Output: -1
Explanation: There is no substring that can be split into power of 5.


Constraints:
1 ≤ s.size() ≤ 30

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(n

*/


class Solution {
public:
    bool isPowerOfFive(string s) {
        if (s[0] == '0') return false; // no leading zero
        int num = 0;
        for (char c : s) {
            num = num * 2 + (c - '0');
        }
        while (num > 1 && num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
    
    int cuts(string s) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0; // dp[0] means empty string
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i-j);
                if (isPowerOfFive(sub)) {
                    if (dp[j] != INT_MAX)
                        dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};