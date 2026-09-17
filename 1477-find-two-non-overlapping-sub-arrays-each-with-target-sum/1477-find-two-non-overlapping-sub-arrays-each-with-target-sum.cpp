class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = INT_MAX;


        // Hint 1
// Let's create two arrays prefix and suffix where prefix[i] is the minimum length of sub-array ends before i and has sum = k, suffix[i] is the minimum length of sub-array starting at or after i and has sum = k.

        vector<int> prefix(n, INT_MAX);

        int i = 0;
        int j = 0;
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            while(i < j && sum > target){
                sum -= nums[i];
                i++;
            }

            if(sum == target){
                int len = j - i + 1;
                prefix[j] = len;
            }

            if(j >= 1)      prefix[j] = min(prefix[j], prefix[j- 1]);
            j++;
        }

        vector<int> suffix(n, INT_MAX);

        i = n - 1;
        j = n - 1;
        sum = 0;
        while(j >= 0){
            sum += nums[j];
            while(i > j && sum > target){
                sum -= nums[i];
                i--;
            }

            if(sum == target){
                int len = i - j + 1;
                suffix[j] = len;
            }

            if(j < n - 1)      suffix[j] = min(suffix[j], suffix[j + 1]);
            j--;
        }

        for(int i = 1; i < n; i++){
            if(prefix[i - 1] == INT_MAX || suffix[i] == INT_MAX)    continue;    
            int curr = prefix[i - 1] + suffix[i];
            ans = min(ans, curr);
        }


        return ans == INT_MAX ? -1: ans;
    }
};