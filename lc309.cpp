class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int x: nums){
            string s = to_string(x);
            for(char c: s){
                ans.push_back(c - '0');
            }
        }
        return ans;
    }
};