class Solution {
public:

    // ans should be less than equal to n + 1
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(n, 0);

        for(int x: nums){
            if(x > 0 && x <= n){
                temp[x - 1] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            if(temp[i] != 1)    return i + 1;
        }

        return n + 1;
    }
};