class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<long long> prev(k, 0);

        //sum of ans[i] wil be  = n(n + 1) / 2 asthere are total these ways to break the array

        for(int i = 0; i < n; i++){
            vector<long long> curr(k, 0);

            int rem = nums[i] % k;
            curr[rem]++;

            for(int j = 0; j < k; j++){
                int nr = (j * 1LL * nums[i]) % k;//new remainder
                curr[nr] += prev[j];
            }

            for(int j = 0; j < k; j++){
                ans[j] += curr[j];
            }

            prev = curr;
        }

        return ans;
    }
};