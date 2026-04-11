class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)   return -1;
        
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto [x, v]: mpp){
            int m = v.size();
            if(m < 3)   continue;
            for(int i = 0; i < m - 2; i++){
                ans = min(ans, v[i + 2] - v[i]);
            }
        }

        return ans == INT_MAX ? -1 : 2*ans;
    }
};