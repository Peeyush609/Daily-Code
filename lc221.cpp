class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        const long long INF = (long long)4e18;  // similar to Long.MAX_VALUE / 2
        int n = nums.size();
        long long res = -INF;
        long long st1 = -INF;  // stage1: best sum of increasing elements
        long long st2 = -INF;  // stage2: best sum of decreasing elements after increasing elements
        long long st3 = -INF;  // stage3: best sum of increasing elements after stage2

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                st1 = max(st1 + nums[i], (long long)nums[i] + nums[i - 1]);
                st3 = max(st2 + nums[i], st3 + nums[i]);
                res = max(res, st3);
                st2 = -INF;  // the decrease sequence is broken, reset the best sum of stage2
            } else {
                if (nums[i] < nums[i - 1]) {
                    st2 = max(st2 + nums[i], st1 + nums[i]);
                } else { // the case of equal elements
                    st2 = -INF;
                }
                st1 = -INF;
                st3 = -INF;
            }
        }

        return res;
    }
};
