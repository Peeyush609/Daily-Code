class Solution {
public:
    
    const int m = 1e9 + 7;
    
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1; 
    
        deque<int> mind, maxd;
        int l = 0;
        int sumtill = 1;
    
        for (int r = 0; r < n; ++r) {

            while (!maxd.empty() && nums[maxd.back()] <= nums[r])
                maxd.pop_back();
            maxd.push_back(r);
    
            while (!mind.empty() && nums[mind.back()] >= nums[r])
                mind.pop_back();
            mind.push_back(r);
    
            while (nums[maxd.front()] - nums[mind.front()] > k) {
                if (maxd.front() == l) maxd.pop_front();
                if (mind.front() == l) mind.pop_front();
                sumtill = (sumtill - dp[l] + m) % m;
                l++;
            }
    
            dp[r + 1] = sumtill;
            sumtill = (sumtill + dp[r + 1]) % m;
        }
    
        return dp[n];
    }
};