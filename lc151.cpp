class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> ss(nums.begin(), nums.end());

        while(ss.count(original)){
            original *= 2;
        }
        return original;
    }
};