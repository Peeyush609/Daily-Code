class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 3)   return ans;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j + 1])  j++;
                    while(k > j && nums[k] == nums[k - 1])  k--;
                    
                    j++;
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return ans;
    }
};