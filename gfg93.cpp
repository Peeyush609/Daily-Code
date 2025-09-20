#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // nearest strictly greater to the left
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // nearest greater-or-equal to the right
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int length = right[i] - left[i] - 1; // max subarray length where arr[i] is the maximum
            if (arr[i] <= length) ans = max(ans, length);
        }
        return ans;
    }
};
