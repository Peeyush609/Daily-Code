class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n - 1;

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;

        while(i < n){
            while(j < n && (long long)nums[j] <= 1LL*k*nums[i]){
                ans = min(ans, n - (j - i + 1));
                j++;
            }
            i++;
        }

        return ans;
    }
};