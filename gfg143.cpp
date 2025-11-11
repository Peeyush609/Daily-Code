class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
    
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
    
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                
                // If chars match
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                    
                // Else, take max from top or left
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            // Move current row to previous
            prev = curr;
        }
    
        int lcsLen = prev[n];
    
        // SCS length = total - common part (LCS)
        return m + n - lcsLen;
    }
};