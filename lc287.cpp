class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            string rev = s;
            while(s.back() == '0'){
                s.pop_back();
            }
            reverse(rev.begin(), rev.end());

            if(mpp.count(rev)){
                ans = min(ans, i - mpp[rev]);
            }

            mpp[s] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }   
};