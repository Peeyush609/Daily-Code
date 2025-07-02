class Solution {
  public:
    int totalElements(vector<int> &nums) {
        // code here
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0;
        int j = 0;
        
        int ans = 0;
        while(j < n){
            mpp[nums[j]]++;
            
            while(mpp.size() > 2){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            
            ans = max(ans, j - i + 1);
            
            j++;
        }
        
        return ans;
    }
};