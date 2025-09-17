/*

Decode the string

Given an encoded string s, decode it by expanding the pattern k[substring], where the substring inside brackets is written k times. k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets. Return the final decoded string.

Note: The test cases are generated so that the length of the output string will never exceed 105 .

Examples:

Input: s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
Explanation:
Inner substring “2[ca]” breakdown into “caca”.
Now, new string becomes “3[bcaca]”
Similarly “3[bcaca]” becomes “bcacabcacabcaca” which is final result.


Input: s = "3[ab]"
Output: "ababab"
Explanation: The substring "ab" is repeated 3 times giving "ababab".


Constraints:
1 ≤ |s| ≤ 105 
1 ≤ k ≤ 100

Expected Complexities

Time Complexity: O(n)
Auxiliary Space: O(n)

*/

class Solution {
  public:
  
    string decodedString(string &s) {
        string res = "";
        
        for (int i = 0; i < s.length(); i++) {
    
            // If the current character is not a clostring
            // bracket, append it to the result string.
            if (s[i] != ']') {
                res.push_back(s[i]);
            }
    
            else {
                string temp = "";
                while (!res.empty() && res.back() != '[') {
                    temp.push_back(res.back());
                    res.pop_back();
                }
    
                // Reverse the temporary string to obtain the
                // correct substring.
                reverse(temp.begin(), temp.end());
    
                // Remove the opening bracket from the result
                // string.
                res.pop_back();
    
                // Extract the preceding number and convert it
                // to an integer.
                string num = "";
                while (!res.empty() && res.back() >= '0' && res.back() <= '9') {
                    num.push_back(res.back());
                    res.pop_back();
                }
                reverse(num.begin(), num.end());
                int p = stoi(num);
    
                // Append the substring to the result string,
                // repeat it to the required number of times.
                while (p--) {
                    res.append(temp);
                }
            }
        }
    
        // Return the decoded string.
        return res;
    }
};