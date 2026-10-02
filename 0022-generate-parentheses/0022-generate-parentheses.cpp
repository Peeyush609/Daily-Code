class Solution {
public:

    void solve(vector<string>& ans, int close, int open, string curr, int n, int i){
        if(close == 0){
            ans.push_back(curr);
            return;
        }

        if(open > 0){
            solve(ans, close - 1, open - 1, curr + ')', n, i);
        }
        if(i < n){
            solve(ans, close, open + 1, curr + '(', n, i + 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(ans, n, 0, "", n, 0);

        return ans;
    }
};