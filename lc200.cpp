class Solution {
public:

    int fun(vector<int>& nums1, vector<int>& nums2, int i, int j, int n1, int n2, vector<vector<int>>& dp){
        if(i >= n1 || j >= n2)  return INT_MIN/2;

        if(dp[i][j] != -1)  return dp[i][j];

        int val = nums1[i]*nums2[j];
        // take both
        int both = max(val, val + fun(nums1, nums2, i + 1, j + 1, n1, n2, dp));
        // skip i
        int s1 = fun(nums1, nums2, i + 1, j, n1, n2, dp);
        // skip j
        int s2 = fun(nums1, nums2, i, j + 1, n1, n2, dp);


        return dp[i][j] = max(both, max(s1, s2));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        fun(nums1, nums2, 0, 0, n1, n2, dp);

        return dp[0][0];
    }
};