class Solution {
public:

    // check if we can pick k points such that min distance >= limit
    bool check(long long limit, vector<long long>& arr, int k, int side) {
        for (long long start : arr) {
            long long end = start + 4LL * side - limit;
            long long cur = start;

            for (int i = 0; i < k - 1; i++) {
                auto it = lower_bound(arr.begin(), arr.end(), cur + limit);

                if (it == arr.end() || *it > end) {
                    cur = -1;
                    break;
                }

                cur = *it;
            }

            if (cur >= 0) return true;
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        // 2D → 1D mapping (same as yours)
        for (auto& p : points) {
            int x = p[0], y = p[1];

            if (x == 0) {
                arr.push_back(y);
            } 
            else if (y == side) {
                arr.push_back(side + x);
            } 
            else if (x == side) {
                arr.push_back(3LL * side - y);
            } 
            else {
                arr.push_back(4LL * side - x);
            }
        }

        sort(arr.begin(), arr.end());

        long long lo = 1, hi = side;
        long long ans = 0;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;

            if (check(mid, arr, k, side)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)ans;
    }
};