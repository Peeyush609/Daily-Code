class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s2;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                s2.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> s3;
        for(int x: s2){
            for(int y: nums){
                s3.insert(x ^ y);
            }
        }

        return s3.size();
    }
};