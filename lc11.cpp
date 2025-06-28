class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> s= nums;
        sort(s.rbegin(), s.rend());
        unordered_multiset<int> ss;
        for(int i = 0; i < k;i++){
            ss.insert(s[i]);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(ss.find(nums[i]) != ss.end()){
                ans.push_back(nums[i]);
                ss.erase(ss.find(nums[i]));
            }
        }
        return ans;
    }
};