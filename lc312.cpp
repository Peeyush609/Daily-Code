class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(int i = 1; i < n - 1; i++){
            if(mpp[i] != 1){
                return false;
            }
        }
        
        return mpp[n - 1] == 2;
    }
};