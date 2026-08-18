class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n)  return *max_element(nums.begin(), nums.end());

        // the ans is either the first or last no. if they are single element ie freq = 1 or the ans is -1 
        vector<int> freq(51, 0);
        for(int x: nums){
            freq[x]++;
        }

        int ans = -1;
        if(freq[nums[0]] == 1)  ans = nums[0];   
        if(freq[nums[n - 1]] == 1)  ans = max(ans, nums[n - 1]);  

        if(k == 1){
            for(int i = 0; i <= 50; i++){
                if(freq[i] == 1){
                    ans = max(ans, i);
                }
            }
        } 

        return ans;
    }
};