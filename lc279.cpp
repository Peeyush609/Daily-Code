class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        int mod = 1e9 + 7;
        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for(int idx = l; idx <= r; idx += k){
                nums[idx] = ((long long)nums[idx]*v) % mod;
            }
        }
        int ans = 0;
        for(int x:nums){
            ans = ans ^ x;
        }
        
        return ans;
    }
};