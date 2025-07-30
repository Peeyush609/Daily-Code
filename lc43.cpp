class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //we have to return the length of the longest subarray with maximum bitwise AND
        //cant do in n**2 by exploring all the subarrays
        // IMP: a AND b <= max(a, b)
        //so if the max no. repeats then length will be no. of times it repeats CONTINUOUSLY or len will be 1
        int n = nums.size();
        int maxi = 0;
        for(int x : nums)   maxi = max(maxi, x);

        int count = 0;
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                count++;
            }else{
                count = 0;
            }
            maxlen = max(maxlen, count);
        }
        return maxlen;
    }
};