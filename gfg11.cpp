/*
Substrings of length k with k-1 distinct elements
Difficulty: MediumAccuracy: 57.85%Submissions: 28K+Points: 4Average Time: 15m
Given a string s consisting only lowercase alphabets and an integer k. Find the count of all substrings of length k which have exactly k-1 distinct characters.

Examples:

Input: s = "abcc", k = 2
Output: 1
Explaination: Possible substring of length k = 2 are,
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct characters
Only one valid substring so, count is equal to 1.
Input: "aabab", k = 3
Output: 3
Explaination: Possible substring of length k = 3 are, 
aab : 2 distinct charcters
aba : 2 distinct characters
bab : 2 distinct characters
All these substring are valid so, the total count is equal to 3.
Constrains:
1 ≤ s.size() ≤ 105
2 ≤ k ≤ 27
*/

class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.size();
        
        int ans = 0;
        unordered_map<int, int> mpp;
        int i = 0;
        int j = 0;
        
        while(j < k){
            mpp[s[j]]++;
            j++;
        }
        
        if((int)mpp.size() == k - 1)  ans++;
        while(j < n){

            mpp[s[i]]--;
            mpp[s[j]]++;
            if(mpp[s[i]] == 0){
                mpp.erase(s[i]);
            }
            
            if((int)mpp.size() == k - 1)  ans++;
            i++;
            j++;
        }
        
        
        return ans;
    }
};