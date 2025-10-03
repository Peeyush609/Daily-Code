class Solution {
public:
    void dfs(const vector<int>& arr, vector<string>& ans, int idx,
             const vector<string>& mpp, string& curr) {
        if (idx == arr.size()) {
            if (!curr.empty()) ans.push_back(curr); // only push non-empty words
            return;
        }

        const string& letters = mpp[arr[idx]];
        if (letters.empty()) {
            // no letters for this digit (e.g. 0 or 1) — skip it
            dfs(arr, ans, idx + 1, mpp, curr);
            return;
        }

        for (char c : letters) {
            curr.push_back(c);
            dfs(arr, ans, idx + 1, mpp, curr);
            curr.pop_back();
        }
    }

    vector<string> possibleWords(vector<int>& arr) {
        vector<string> mpp = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> ans;
        string curr;
        dfs(arr, ans, 0, mpp, curr);
        return ans;
    }
};
