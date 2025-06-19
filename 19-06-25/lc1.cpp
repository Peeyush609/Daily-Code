class Solution {
public:

    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        int i = 0;
        while(i < n){
            int st = nums[i];
            while(i < n && nums[i] - st <= k){
                i++;
            }
            ans++;
        }

        return ans;
    }
};