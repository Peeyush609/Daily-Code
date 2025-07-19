/*


Count Unique Vowel Strings

You are given a lowercase string s, determine the total number of distinct strings that can be formed using the following rules:

Identify all unique vowels (a, e, i, o, u) present in the string.
For each distinct vowel, choose exactly one of its occurrences from s. If a vowel appears multiple times, each occurrence represents a unique selection choice.

Generate all possible permutations of the selected vowels. Each unique arrangement counts as a distinct string.
Return the total number of such distinct strings.

Examples:

Input: s = "aeiou"
Output: 120
Explanation: Each vowel appears once, so the number of different strings can form is 5! = 120.


Input: s = "ae"
Output: 2
Explanation: Pick a and e, make all orders → "ae", "ea".
Input: s = "aacidf"
Output: 4 
Explanation: Vowels in s are 'a' and 'i', Pick each 'a' once with a single 'i', make all orders → "ai", "ia", "ai", "ia".


Constraints:
1 ≤ s.size() ≤ 100

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

*/


class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        int n = s.size();
        
        unordered_map<char, int> mpp;
        for(char c: s){
            mpp[c]++;
        }
        
        int distinct_vowels = 0;
        int factor = 1;
        for(auto it: mpp){
            auto c = it.first;
            auto f = it.second;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                distinct_vowels++;
                factor = factor * f;
            }
        }
        
        // there can be max of 5 distinct vowels
        
        // make sure fact 0 is 0 beacuse if no vowels then ans is zero
        vector<int> fact = {0, 1, 2, 6, 24, 120};
        int ans = factor * fact[distinct_vowels];
        return ans;
    }
};