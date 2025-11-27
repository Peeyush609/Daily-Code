class Solution {
  public:
    int subsetXORSum(vector<int> &arr) {
        int n = arr.size();
        int bits = 0;
    
        // Finding bitwise OR of all elements
        for (int i=0; i < n; ++i)
            bits |= arr[i];
    
        int ans = bits * pow(2, n-1);
    
        return ans;
    }
};