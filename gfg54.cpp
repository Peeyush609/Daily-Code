class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int target = (n + 1) / 2; // ceil(n/2)

        int lucky = 0;
        vector<int> cost;

        for (int x : arr) {
            if (x % k == 0) {
                lucky++;
            } else {
                cost.push_back((k - (x % k)) % k);
            }
        }

        if (lucky >= target) return 0;

        sort(cost.begin(), cost.end());

        int soldiers = 0;
        for (int i = 0; i < target - lucky; i++) {
            soldiers += cost[i];
        }

        return soldiers;
    }
};
