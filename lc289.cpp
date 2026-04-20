class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;

        for(int i = 0; i < n; i ++){
            int ind = upper_bound(nums2.begin() + i, nums2.end(), nums1[i], greater<int>()) - nums2.begin();

            ans = max(ans, ind - i - 1);
        }

        return ans;
    }
};