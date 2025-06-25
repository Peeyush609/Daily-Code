/*
Check if frequencies can be equal
Difficulty: MediumAccuracy: 16.67%Submissions: 126K+Points: 4
Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the  frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.

Examples:

Input: s = "xyyz"
Output: true 
Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
Input: s = "xyyzz"
Output: true
Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
Input: s = "xxxxyyzz"
Output: false
Explanation: Frequency can not be made same by removing at most one character.
Constraints:
1 ≤ s.size() ≤ 105
*/

class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        
        unordered_map<char, int> mpp;
        for(char c:s){
            mpp[c]++;
        }
        
        unordered_map<int, int> mpp2;
        for(auto it : mpp){
            mpp2[it.second]++;
        }
        
        if(mpp2.size() > 2)    return false;
        if(mpp2.size() == 1)   return true;
        
        auto it = mpp2.begin();
        int a = it->first;
        int f1 = it->second;
        int b = next(it)->first;
        int f2 = next(it)->second;
        
        if(a < b){
            swap(a, b);
            swap(f1, f2);
        }
        
        return ((a - b == 1 && f1 == 1) || (b == 1 && f2 == 1));
    }
};