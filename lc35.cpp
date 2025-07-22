class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0; 
        int j = 0;

        int ans = 0;
        int sum = 0;
        
        unordered_map<int, int> mpp;
        while(j < n){
            mpp[nums[j]]++;
            sum += nums[j];

            while(i < j && mpp.size() < (j - i + 1)){
                mpp[nums[i]]--;
                sum -= nums[i];
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }

            ans = max(ans, sum);
            j++;
        }

        return ans;
    }
};