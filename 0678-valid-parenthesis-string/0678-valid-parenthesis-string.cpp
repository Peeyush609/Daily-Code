class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Minimum possible open parentheses
        int high = 0; // Maximum possible open parentheses

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;   // `*` acts as `)`
                high++;  // `*` acts as `(`
            }

            if(low<0)   low=0;
            
            if (high < 0) { // Too many closing parentheses
                return false;
            }
        }

        return low == 0; // Valid if all open parentheses can be closed
    }
};
