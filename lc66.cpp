class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int lm1 = n;//left most
        int rm1 = 0;//right most
        int tm1 = m;//top most
        int bm1 = 0;//bottom most

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    lm1 = min(lm1, j);
                    rm1 = max(rm1, j);
                    tm1 = min(tm1, i);
                    bm1 = max(bm1, i);
                }
            }
        }

        cout<<lm1<<" "<<rm1<<" "<<tm1<<" "<<bm1;

        return (bm1 - tm1 + 1)*(rm1 - lm1 + 1);
    }
};