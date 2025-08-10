/*

Palindrome SubStrings

Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2.

Note: A substring is palindromic if it reads the same forwards and backwards.

Examples:

Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings (of length > 1) are: "aba", "aa", "baab".

Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings (of length > 1) are: "aa", "aa", "aaa".

Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings (of length > 1) are: "bb", "abba", "aea", "eae".

Constraints:
2 ≤ s.size() ≤ 5 * 103
s contains only lowercase english characters

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(1)

*/

class Solution {
  public:
    int countPS(string& s) {
    
        int n = s.size();
        int count = 0;
      
        // count odd length palndrome substrings 
        // with str[i] as center.
        for (int i = 0; i < s.size(); i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 and right < n) {
                if (s[left] == s[right])
                    count++;
                else
                    break;
                left--;
                right++;
            }
        }
    
        // count even length palindrome substrings
        // where str[i] is first center.
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i + 1;
            while (left >= 0 and right < n) {
                if (s[left] == s[right])
                    count++;
                else
                    break;
                left--;
                right++;
            }
        }
        return count;
    }
};