class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        
        int last = -n-1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                if(i - last <= k)   return false;
                last = i;    
            }
        }

        return true;
    }
};