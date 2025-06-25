class Solution {
public:
    long long fun(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long count = 0;
        int m = nums2.size();

        for (int a : nums1) {
            if (a == 0) {
                if (mid >= 0) count += m;
            } else if (a > 0) {
                // Binary search: count of b such that a * b <= mid
                int low = 0, high = m - 1, pos = -1;
                while (low <= high) {
                    int midIdx = (low + high) / 2;
                    if ((long long)a * nums2[midIdx] <= mid) {
                        pos = midIdx;
                        low = midIdx + 1;
                    } else {
                        high = midIdx - 1;
                    }
                }
                count += (pos + 1);
            } else { // a < 0
                // Binary search: count of b such that a * b <= mid
                int low = 0, high = m - 1, pos = m;
                while (low <= high) {
                    int midIdx = (low + high) / 2;
                    if ((long long)a * nums2[midIdx] <= mid) {
                        pos = midIdx;
                        high = midIdx - 1;
                    } else {
                        low = midIdx + 1;
                    }
                }
                count += (m - pos);
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long low = -1e10, high = 1e10, ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = fun(nums1, nums2, mid);

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
