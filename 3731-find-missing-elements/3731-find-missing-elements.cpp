class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        
        unordered_set<int> ss(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i = mini; i < maxi; i++){
            if(!ss.count(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};