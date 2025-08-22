class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> nums;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                nums.push_back(mat[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        
        return nums[n*m/2];
    }
};
