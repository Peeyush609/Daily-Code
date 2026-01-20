class Solution {
public:
    int value(int x){
        // we need to find ans such that ans OR ans + 1 = x
        for(int i = 0; i < x; i++){
            if((i | (i+1)) == x) return i;
        }

        return -1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            ans[i] = value(nums[i]);
        }

        return ans;
    }
};