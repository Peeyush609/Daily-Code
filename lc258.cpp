class Solution {
public:

    int solve(vector<int>& curr){
        int ans = 0;

        for(int i = 0; i < curr.size(); i++){
            int val = curr[i]*(i+1);
            ans = max(ans, val);
        }

        return ans;
    }

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> col(m, vector<int>(n, 0));

        int cont = 0;
        for(int j = 0; j < n; j++){
            cont = 0;
            for(int i = 0; i < m; i++){
                if(matrix[i][j] == 1){
                    cont++;
                }
                else    cont = 0;

                col[i][j] = cont;
            }
        }
        int ans = 0;

        for(int i = 0; i < m; i++){
            vector<int> curr = col[i];
            
            sort(curr.rbegin(), curr.rend());

            int value = solve(curr);
            ans = max(ans, value);
        }

        return ans;
    }
};