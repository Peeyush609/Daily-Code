class Solution {
public:
    // Function to check if t * k is a subsequence of s
    bool check(string& t, string& s, int k) {
        int j = 0, count = 0;
        for (char c : s) {
            if (c == t[j]) j++;
            if (j == t.size()) {
                j = 0;
                count++;
            }
            if (count == k) return true;
        }
        return false;
    }

    void dfs(string& s, string& curr, string& best, int k, vector<char>& chars, int maxLen) {
        if (curr.size() > maxLen) return;

        if (curr.size() > best.size() || (curr.size() == best.size() && curr > best)) {
            if (check(curr, s, k)) {
                best = curr;
            }
        }

        for (char c : chars) {
            curr.push_back(c);
            dfs(s, curr, best, k, chars, maxLen);
            curr.pop_back();
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();

        unordered_map<char, int> mpp;
        for (char c : s) mpp[c]++;

        // Determine how many times each char can appear in the longest candidate
        unordered_map<char, int> possible;
        for (auto [c, f] : mpp) {
            if (f / k > 0) {
                possible[c] = f / k;
            }
        }

        // Build character list with repetitions based on possible counts
        string v;
        for (auto [c, f] : possible) {
            for (int i = 0; i < f; i++) {
                v += c;
            }
        }

        sort(v.rbegin(), v.rend());  // Reverse for lexicographical order
        vector<char> chars(v.begin(), v.end());

        string curr = "", best = "";
        dfs(s, curr, best, k, chars, 7);  // limit to length 7
        return best;
    }
};
