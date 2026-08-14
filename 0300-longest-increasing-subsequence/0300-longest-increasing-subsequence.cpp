class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        for(int x: nums){
            if(temp.empty() || temp[temp.size() - 1] < x){
                temp.push_back(x);
            }
            else{
                // frind the index of the smallest element greater than equal to x
                auto it = lower_bound(temp.begin(), temp.end(), x);
                *it = x;
            }
        }

        return temp.size();

    }
};