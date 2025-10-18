class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long nextFree = LLONG_MIN;
        int count = 0;

        for (int x : nums) {
            long long low = (long long)x - k;
            long long high = (long long)x + k;

            long long assign = max(low, nextFree);
            if (assign <= high) {
                count++;
                nextFree = assign + 1;
            }
        }

        return count;
    }
};
