class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        st.reserve(nums.size() * 2);
        st.max_load_factor(0.7);

        for (int x : nums) {
            st.insert(x);
        }

        int ans = 0;

        for (int x : st) {
            // x is the beginning of a sequence
            if (x != INT_MIN && st.count(x - 1)) {
                continue;
            }

            int current = x;
            int length = 1;

            while (current != INT_MAX && st.count(current + 1)) {
                ++current;
                ++length;
            }

            ans = max(ans, length);
        }

        return ans;
    }
};