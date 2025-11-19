class Solution {
  public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCostPath(vector<vector<int>>& heights) {
        // code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e8));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});

        while(!q.empty()){
            int d = q.top()[0];
            int x = q.top()[1];
            int y = q.top()[2];

            q.pop();

            if(x == n - 1 && y == m - 1)    return d;

            for(auto it :  directions){
                int xx = x + it.first;
                int yy = y + it.second;

                if(xx >= 0 && xx < n && yy >= 0 && yy < m && max(d, abs(heights[xx][yy] - heights[x][y])) < diff[xx][yy]){
                    diff[xx][yy] = max(d, abs(heights[xx][yy] - heights[x][y]));
                    q.push({diff[xx][yy], xx, yy});
                }
            } 
        }

        return diff[n - 1][m - 1];
    }
};
