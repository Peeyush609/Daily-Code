class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> ss(nums.begin(), nums.end());
        int val = k;
        while(ss.count(val)){
            val += k;
        }
        return val;
    }
};