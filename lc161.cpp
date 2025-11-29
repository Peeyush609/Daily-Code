class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % k;
    }
};