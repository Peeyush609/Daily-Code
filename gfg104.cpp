class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());   // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> used(arr.size(), false);

        function<void()> backtrack = [&]() {
            if (curr.size() == arr.size()) {
                result.push_back(curr);
                return;
            }
            for (int i = 0; i < arr.size(); i++) {
                if (used[i]) continue;  // Skip if already used
                if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue; // Skip duplicates

                used[i] = true;
                curr.push_back(arr[i]);
                backtrack();
                curr.pop_back();
                used[i] = false;
            }
        };

        backtrack();
        return result;
    }
};
