class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        bool inc = true;
        for(int i = 1; i < n - 2; i++){
            if(nums[i] <= nums[i - 1]) inc = false;
            bool dec = true;
            for(int j = i + 1; j < n - 1; j++){
                if(nums[j] >= nums[j - 1]) dec = false;

                bool last = true;
                for(int k = j + 1; k < n; k++){
                    if(nums[k] <= nums[k - 1]) last = false;
                }

                if((inc && dec) && last) return true;
            }
        }
        return false;
    }
};