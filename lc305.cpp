class Solution {
public:

    vector<int> ans;
    vector<pair<int,int>> prevMax;

    void solve(int r, int rightMin, int rightMax, vector<int>& nums) {

        auto [mx, idx] = prevMax[r];

        int currMax;

        // if all right elements are bigger
        // then component max = current maximum
        if(mx <= rightMin)
            currMax = mx;
        else
            currMax = rightMax;

        int nextRightMin = min(mx, rightMin);

        // fill current component
        for(int i = idx; i <= r; i++) {
            ans[i] = currMax;
            nextRightMin = min(nextRightMin, nums[i]);
        }

        // process left side
        if(idx == 0) return;

        solve(idx - 1, nextRightMin, currMax, nums);
    }

    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        ans.resize(n);

        prevMax.resize(n);

        // store prefix maximum and its index
        pair<int,int> best = {INT_MIN, -1};

        for(int i = 0; i < n; i++) {

            if(nums[i] > best.first) {
                best = {nums[i], i};
            }

            prevMax[i] = best;
        }

        solve(n - 1, INT_MAX, 0, nums);

        return ans;
    }
};