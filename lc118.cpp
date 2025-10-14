class Solution {
public:
    bool possible(int s1, vector<int>& nums, int k){
        for(int i = s1; i < s1 + k - 1; i++){
            if(nums[i] >= nums[i + 1]){
                return false;
            }
        }

        for(int i = s1 + k; i < s1 + 2*k - 1; i++){
            if(nums[i] >= nums[i + 1]){
                return false;
            }
        }

        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = 0; i <= n - 2*k; i++){
            if(possible(i, nums, k)){
                return true;
            }
        }

        return false;
    }
};