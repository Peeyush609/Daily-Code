class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // empty prefix before the array

        int prefixSum = 0;
        int answer = 0;

        for (int x : nums) {
            prefixSum += x;

            answer += freq[prefixSum - k];

            freq[prefixSum]++;
        }

        return answer;
    }
};