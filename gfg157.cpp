class Solution {
  public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        
        // Compute xor(1..n) using the known pattern
        int cur;
        if (n % 4 == 0) cur = n;
        else if (n % 4 == 1) cur = 1;
        else if (n % 4 == 2) cur = n + 1;
        else cur = 0;

        int diff = cur ^ n;

        // If diff == 0, we keep all numbers
        if (diff == 0) {
            for (int i = 1; i <= n; i++) ans.push_back(i);
        } 
        else {
            // Remove one number (diff)
            for (int i = 1; i <= n; i++) {
                if (i != diff) ans.push_back(i);
            }
        }

        return ans;
    }
};
