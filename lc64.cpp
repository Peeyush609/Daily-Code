//1277

class Solution {
public:
    //tabulation approach 

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        //base cases copy the row and column as it is
        for(int i = 0; i < m; i++)      dp[i][0] = matrix[i][0];
        for(int j = 0; j < n; j++)      dp[0][j] = matrix[0][j];

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                if(matrix[i][j] == 1){
                    int up = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    int diag = dp[i - 1][j - 1];
                    int mini = min(min(up, left), diag);
                    
                    dp[i][j] = mini + 1;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                count += dp[i][j];
            }
        }

        return count;
    }
};