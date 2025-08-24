class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int i = 0; 
        int j = 0;
        int z = 0;//no. of zeroes in current window

        while(j < n){
            if(nums[j] == 0)    z++;

            while(z > 1){
                if(nums[i] == 0)    z--;
                i++;
            }

            ans = max(ans, j - i);
            j++;
        }

        return ans;
    }
};