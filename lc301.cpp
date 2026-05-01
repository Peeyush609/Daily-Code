class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int F_prev = 0;
        int total_sum = 0;
        // O(n)
        for(int i = 0; i < n; i++){
            F_prev += i*(nums[i]);
            total_sum += nums[i];
        }

        int ans = F_prev;
        // O(n)
        for(int i = 1; i < n; i++){
            int F_curr = F_prev + (n)*nums[i - 1] - (total_sum);
            ans = max(ans, F_curr);
            F_prev = F_curr;
        }
        return ans;
    }
};