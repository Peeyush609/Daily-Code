class Solution {
public:
    void fun(int o, int c, vector<string>& ans, string curr){
        if(o == 0 && c == 0){
            ans.push_back(curr);
        }
        //add open bracket
        if(o > 0){
            fun(o - 1, c, ans, curr + '(');
        }
        //add close bracket only if there are open bracket previously
        if(c > 0 && o < c){
            fun(o, c - 1, ans, curr  + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(n, n, ans, "");
        return ans;
    }
};