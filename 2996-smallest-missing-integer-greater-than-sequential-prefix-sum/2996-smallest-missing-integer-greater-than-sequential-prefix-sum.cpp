class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1] + 1)  break;
            sum += nums[i];
        }

        unordered_set<int> vals(nums.begin(), nums.end());
        int ans = sum;
        while(vals.count(ans)){
            ans++;
        }

        return ans;
    }
};