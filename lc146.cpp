class Solution {
public:
    //normal recursion with memoization
    int dp[601][101][101];

    //helper fxn to find no. of zeroes and ones in current string
    //O(100) at max
    vector<int> zo(string s){
        int z = 0;
        int o = 0;

        for(char c: s){
            if(c == '0')    z++;//zero
            else            o++;//ones
        }

        return {z, o};
    }
    
    int fun(int i, vector<string>& strs, int m, int n){
        if(i == strs.size() || (m == 0 && n == 0)){
            return 0;
        }

        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }

        vector<int> zov = zo(strs[i]);
        int z = zov[0];//zeroes
        int o = zov[1];//ones

        int take = 0;
        if(z <= m && o <= n){
            take = 1 + fun(i + 1, strs, m - z, n - o);
        }
        int skip = fun(i + 1, strs, m, n);

        return dp[i][m][n] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        memset(dp, -1, sizeof(dp));//set all values of dp to -1
        return fun(0, strs, m, n);
    }
};