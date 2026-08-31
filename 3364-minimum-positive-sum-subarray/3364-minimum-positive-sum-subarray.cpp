class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        

        vector<int> prefix(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            prefix[i] = sum;
        }

        for(int i = 0; i <= n - l; i++){
            for(int j = i+ l - 1; j <= min(i + r - 1, n-1); j++){
                int curr = prefix[j];
                if(i > 0)   curr -= prefix[i - 1];

                if(curr > 0)    ans = min(ans, curr);
            }
        }


        return ans == INT_MAX ? -1: ans;
    }
};