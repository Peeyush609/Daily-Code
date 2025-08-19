class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        long long count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                ans += count*(count + 1)/2;
                count = 0;
            }
            else{
                count++;
            }
        }
        ans += count*(count + 1)/2;
        return ans;
    }
};