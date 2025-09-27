class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0);  // mark flip starts
        int flipCount = 0;  // active flips
        int ans = 0;
    
        for (int i = 0; i < n; i++) {
            // If a flip effect ends here, remove it
            if (i >= k) {
                flipCount ^= isFlipped[i - k];
            }
    
            // Current value after considering flips
            int curr = arr[i] ^ flipCount;
    
            if (curr == 0) { // need to flip
                if (i + k > n) return -1; // not enough space
                ans++;
                flipCount ^= 1;  // add new flip
                isFlipped[i] = 1; // mark flip started
            }
        }
        return ans;
    }
};