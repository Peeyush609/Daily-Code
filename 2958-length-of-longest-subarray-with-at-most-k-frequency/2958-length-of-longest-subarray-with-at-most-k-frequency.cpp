class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        int i = 0;
        int j = 0;

        unordered_map<int, int> mpp;
        while(j < n){ 
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
 
        return ans;
    }
};