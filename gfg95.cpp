class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), len(n + 1, 0);
        stack<int> st;
    
        // find window sizes for each element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int top = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                int windowSize = right - left - 1;
                len[windowSize] = max(len[windowSize], arr[top]);
            }
            st.push(i);
        }
    
        // process remaining elements in stack
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = n;
            int windowSize = right - left - 1;
            len[windowSize] = max(len[windowSize], arr[top]);
        }
    
        for (int i = 1; i <= n; i++) {
            res[i - 1] = len[i];
        }
    
        for (int i = n - 2; i >= 0; i--) {
            res[i] = max(res[i], res[i + 1]);
        }
    
        return res;
    }
};