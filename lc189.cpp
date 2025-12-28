class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for(auto it: grid){
            for(int x: it){
                if(x<0) ans++;
            }
        }

        return ans;
    }
};