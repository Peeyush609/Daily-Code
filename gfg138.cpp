class Solution {
  public:
    int numberOfWays(int n) {
    
        // Base cases
        if (n == 0 || n == 1) return 1;
    
        int prev2 = 1;  
        int prev1 = 1;  
        
        // Iterate from 2 to n to build the result 
        for (int i = 2; i <= n; i++) {
            
            // Current state depends on the sum of previous two states
            int curr = prev1 + prev2;  
            
            // Move the variables one step ahead
            prev2 = prev1;  
            prev1 = curr; 
        }
    
        return prev1;
    }
};