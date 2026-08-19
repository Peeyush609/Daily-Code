class Solution {
public: 
    void solve(vector<int>& nums, vector<int>& visited, vector<vector<int>>& ans, vector<int>& curr, int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == 1) continue;
            visited[i] = 1;
            curr.push_back(nums[i]);
            solve(nums, visited, ans, curr, n);
            curr.pop_back();
            visited[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        vector<int> curr;
        vector<int> visited(n, 0);
        solve(nums, visited, ans, curr, n);

        return ans;
    }
};