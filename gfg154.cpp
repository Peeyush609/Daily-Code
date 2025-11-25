class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int N = arr.size();
        int res = 0;

        for (int i = 0; i < N; i++) {
            // Number of subarrays where arr[i] appears
            long long freq = (long long)(i + 1) * (N - i);

            // If it appears odd number of times, include in result
            if (freq & 1)
                res ^= arr[i];
        }

        return res;
    }
};
