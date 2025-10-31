class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ss;
        vector<int> ans;

        for(int x: nums){
            if(ss.count(x)){
                ans.push_back(x);
            }
            else{
                ss.insert(x);
            }
        }

        return ans;
    }
};