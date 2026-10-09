class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = ""; // To store the final result
        int balance = 0; // To track the balance of parentheses
        int start = 0; // To track the start of a primitive part

        // Traverse through the string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Increment balance for open parentheses
                balance++;
            } else {
                // Decrement balance for close parentheses
                balance--;
            }
            
            // If balance reaches 0, we have found a primitive string
            if (balance == 0) {
                // Add the current primitive substring without the outermost parentheses
                result += s.substr(start + 1, i - start - 1);
                // Update the start for the next primitive part
                start = i + 1;
            }
        }
        
        return result;
    }

};