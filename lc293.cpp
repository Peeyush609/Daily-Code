class Solution {
public:

    // brute force 
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mpp;
        // O(n)
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }

        for(auto [x, v]: mpp){

            long long sum = 0;
            int m = v.size();
            vector<long long> prefix(m, 0);

            for(int i = 0; i < m; i++){
                prefix[i] = sum;
                sum += v[i];
            }

            for(int i = 0; i < m; i++){
                long long val = 0;
                val += 1LL*i*v[i] - prefix[i];//for back indices
                val += (sum - v[i] - prefix[i]) - 1LL*(m - i - 1)*v[i];//for forward indices

                ans[v[i]] = val;
            }

        }

        return ans;
    }
};