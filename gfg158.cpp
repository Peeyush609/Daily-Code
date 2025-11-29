class Solution {
  public:
    int countSetBits(int n) {
        // Base case
        if (n == 0)
            return 0;
    
        // Find highest power of 2 less than or equal to n
        int x = log2(n);
    
        //Set bits in the full pattern 0 to (2^x - 1)
        int fullBits = x * (1 << (x - 1));
    
        //Contribution of the highest bit from 2^x to n
        int msbBits = n - (1 << x) + 1;
    
        //Recursively count remaining set bits after removing highest bit
        int remaining = n - (1 << x);
        int remainingBits = countSetBits(remaining);
    
        // Total set bits
        return fullBits + msbBits + remainingBits;
    }

};
