class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> nums;
        int rem = grid[0][0] % x;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n ; j++) {
                if(grid[i][j] % x != rem) {
                    return -1; // If different remainder, impossible to make all equal.
                }
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2]; 
        int ops = 0;

        for(int num : nums) {
            ops += abs(num - median) / x;
        }

        return ops;
    }
};