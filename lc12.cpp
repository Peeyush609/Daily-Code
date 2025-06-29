class Solution {
public:
    int mod = 1000000007;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> power_2(n + 1, 1);
        for(int i = 1; i <= n; i++){
            power_2[i] = (power_2[i - 1]*2)%mod;
        }

        int ans = 0;
        int i = 0;
        int j = n-1;
        while(i <= j){
            int sum = nums[i] + nums[j];
            if(sum <= target){
                ans = (ans + power_2[j-i] ) % mod;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};