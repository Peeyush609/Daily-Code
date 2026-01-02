class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;

        unordered_set<int> ss;
        for(int x: nums){
            if(ss.count(x)) return x;
            ss.insert(x);
        }

        return -1;
    }
};