class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        unordered_set<int> ss(nums.begin(), nums.end());

        int val = k;
        while(ss.count(val)){
            val += k;
        }

        return val;
    }
};