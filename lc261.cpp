class Solution {
public:
    int fun(vector<vector<int>>& grid, int x, int y, int k){
        //now we have to take a submat having topleft corner as (x, y)

        set<int> ss;
        for(int i = x; i < x + k; i++){
            for(int j = y; j < y + k; j++){
                ss.insert(grid[i][j]);
            }
        }

        //if all elements are same
        if(ss.size() == 1) return 0;

        int mini = INT_MAX;
        auto it = ss.begin();

        int prev = *it;
        it++;

        for(; it != ss.end(); it++){
            int curr = *it;
            mini = min(mini, curr - prev);
            prev = curr;
        }

        return mini;
    }
    
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        //values should be distinct
        //put all elements of submatrix in the set and see diff bw every consecutive

        for(int i = 0; i < m - k + 1; i ++){
            for(int j = 0; j < n - k + 1; j++){
                ans[i][j] = fun(grid, i, j, k);
            }
        }

        return ans;
    }
};