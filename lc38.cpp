class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> ss;
        for(int x: nums){
            if(x > 0)   ss.insert(x);
        }

        if(ss.size()==0)    return *max_element(nums.begin(), nums.end());

        int ans = 0;
        for(int x: ss){
            ans += x;
        }
        return ans;

    }
};