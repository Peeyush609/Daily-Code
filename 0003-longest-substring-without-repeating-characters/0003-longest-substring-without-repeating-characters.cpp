class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;

        int i = 0;
        int j = 0;

        unordered_set<int> present;
        while(i < n && j < n){
            while(present.count(s[j])){
                present.erase(s[i]);
                i++;
            }
            present.insert(s[j]);
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};