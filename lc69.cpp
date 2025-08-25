class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // focus on sum of i and j means indices of row and col
        // if odd sum reverse and if even then direct 

        map<int, vector<int>> mpp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mpp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        for(auto [sum, v]: mpp){
            if(sum %2 == 0){
                reverse(v.begin(), v.end());
            }
            for(auto x: v){
                ans.push_back(x);
            }
        }

        return ans;
    }
};