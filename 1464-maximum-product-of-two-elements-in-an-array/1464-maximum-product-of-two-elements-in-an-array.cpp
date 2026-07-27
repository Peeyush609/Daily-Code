class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            nums[i]--;
        }
        sort(nums.begin(), nums.end());

        int ans = max(nums[n - 1]*nums[n - 2], nums[0]*nums[1]);

        return ans;
    }
};