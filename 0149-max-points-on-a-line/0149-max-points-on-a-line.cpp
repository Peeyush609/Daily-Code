class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int overlap = 0, currMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // same point
                if (dx == 0 && dy == 0) {
                    overlap++;
                    continue;
                }

                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                string key = to_string(dx) + "#" + to_string(dy);
                mp[key]++;
                currMax = max(currMax, mp[key]);
            }

            ans = max(ans, currMax + overlap + 1);
        }

        return ans;
    }
};