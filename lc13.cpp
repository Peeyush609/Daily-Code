class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mpp;
        for(int x: nums){
            mpp[x]++;
        }

        int ans = 0;
        for(auto [x, f]: mpp){
            if(mpp.count(x+1)){
                ans = max(ans, f + mpp[x+1]);
            }
        }

        return ans;
    }
};