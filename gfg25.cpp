/*

Divisible by 13

Given a number represented as a string s (which may be very large), check whether it is divisible by 13 or not.

Examples:

Input : s = "2911285"
Output : true
Explanation: 2911285 / 13 = 223945, which is a whole number with no remainder.


Input : s = "27"
Output : false
Explanation: 27 / 13 ≈ 2.0769..., which is not a whole number (there is a remainder).


Constraints:
1 ≤  s.size()  ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

*/

class Solution {
  public:
  
    bool divby13(string &s){
        // Stores running remainder
        int rem = 0;
    
        // Process each digit and compute remainder modulo 13
        for (char ch : s) {
            rem = (rem * 10 + (ch - '0')) % 13;
        }
        
        // Final check for divisibility
        return rem == 0;
    }
};