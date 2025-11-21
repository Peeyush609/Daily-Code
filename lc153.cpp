class Solution {
public:

//here the crucial point to notice is that we require palindrome subequence of length 3 only
//palindrome of 3 means first and last same and middle csn be anything
//if any letter repeats that it can create the no. palindrome of length 3 equal to the no. of letters bw both the duplicates

    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<char, int> first, last;

        // Step 1: Find first and last occurrences of each character
        for (int i = 0; i < n; i++) {
            if (first.find(s[i]) == first.end()) {
                first[s[i]] = i;
            }
            last[s[i]] = i;
        }

        int ans = 0;

        // Step 2: Count unique characters between first and last occurrences
        for (auto& [ch, start] : first) {
            int end = last[ch];
            if (end - start > 1) {
                unordered_set<char> unique_chars(s.begin() + start + 1, s.begin() + end);
                ans += unique_chars.size();
            }
        }

        return ans;
    }

};