class Solution {
public:
    int mod = 1000000007;

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        unordered_map<int, int> prev;
        unordered_map<int, int> suff;

        for(int i = 0; i < n ; i++){
            suff[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            suff[nums[i]]--;
            if(suff[nums[i]] == 0)  suff.erase(nums[i]);

            int req = nums[i]*2;

            if(prev.count(req) && suff.count(req)){
                ans = (ans + 1LL*prev[req] * suff[req]);
            }
            prev[nums[i]]++;
        }
        return ans % mod;
    }
};