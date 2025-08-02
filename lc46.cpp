class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int mini = INT_MAX;

        // Count total frequency and track global minimum
        for (int x : basket1) {
            freq[x]++;
            mini = min(mini, x);
        }
        for (int x : basket2) {
            freq[x]++;
            mini = min(mini, x);
        }

        // Check for impossible case
        for (auto [x, f] : freq) {
            if (f % 2 != 0) return -1;
        }

        // Count individual frequencies
        unordered_map<int, int> count1;
        for (int x : basket1) count1[x]++;

        // Separate surplus elements
        vector<int> extra1, extra2;

        for (auto [x, f] : freq) {
            int need = f / 2;
            int in1 = count1[x];
            int in2 = f - in1;

            if (in1 > need) {
                for (int i = 0; i < in1 - need; ++i) {
                    extra1.push_back(x);
                }
            } else if (in2 > need) {
                for (int i = 0; i < in2 - need; ++i) {
                    extra2.push_back(x);
                }
            }
        }

        sort(extra1.begin(), extra1.end());              // smallest first
        sort(extra2.rbegin(), extra2.rend());            // largest first

        long long cost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            cost += min({extra1[i], extra2[i], 2 * mini});
        }

        return cost;
    }
};
