class Solution {
  public:
    void buildExpr(vector<string>& res, string expr, string digits,
        int target, int idx, int eval, int last) {
    
        if (idx == digits.length()) {
            if (eval == target)
                res.push_back(expr);
            return;
        }
    
        for (int i = idx; i < digits.length(); i++) {
            
            // Skip numbers with leading zero
            if (i != idx && digits[idx] == '0') break;
    
            string part = digits.substr(idx, i - idx + 1);
            int num = stoll(part);
    
            if (idx == 0) {
                buildExpr(res, part, digits, target, i + 1, num, num);
            } else {
                buildExpr(res, expr + "+" + part, digits, target, i + 1, eval + num, num);
                buildExpr(res, expr + "-" + part, digits, target, i + 1, eval - num, -num);
                buildExpr(res, expr + "*" + part, digits, target, i + 1,
                          eval - last + last * num, last * num);
            }
        }
    }
    
    // Function to return valid expressions
    vector<string> findExpr(string digits, int target) {
        vector<string> res;
        buildExpr(res, "", digits, target, 0, 0, 0);
        return res;
    }
    
    void showExpr(const vector<string>& res) {
        if (res.empty()) {
            cout << "[]" << endl;
        } else {
            for (const string& e : res)
                cout << e << " ";
            cout << endl;
        }
    }
};