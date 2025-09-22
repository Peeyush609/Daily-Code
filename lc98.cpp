class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        for(int x: nums){
            mpp[x]++;
        }

        int maxi = 0;
        for(auto [x, f]: mpp){
            maxi = max(maxi, f);
        }

        int ans = 0;
        for(int x: nums){
            if(mpp[x] == maxi)  ans++;
        }
        return ans;
    }
};