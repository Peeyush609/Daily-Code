class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long first = *max_element(nums.begin(), nums.end());
        long long second = LLONG_MIN;
        
        for(int x: nums){
            if(x < first){
                second = max(second, (long long)x);
            }
        }

        if(second == LLONG_MIN)    return first;
        long long third = LLONG_MIN;
        for(int x: nums){
            if(x < second){
                third = max(third, (long long)x);
            }
        }

        return third == LLONG_MIN ? first : third;
    }
};