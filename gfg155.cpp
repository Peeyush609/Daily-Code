class Solution {
  public:
    int andInRange(int l, int r) {
    
        int shiftCount = 0;
    
        // Iterate through every bit of a and b
        // simultaneously if a == b then we know that beyond
        // that the AND value will remain constant
        while (l != r && l > 0) {
            shiftCount++;
            l = l >> 1;
            r = r >> 1;
        }
    
        return (l << shiftCount);
    }
};
