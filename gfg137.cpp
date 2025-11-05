class Solution {
  public:
    // Function to find count of minimum squares 
    // that sum to n
    int minSquaresRec(int n, vector<int>& memo) {
      
        // base case: minSquares(1) = 1
        // minSquares(2) = 2
      	// minSquares(3) = 3
        if (n <= 3)
            return n;
      	
      	// if the result for this subproblem is 
        // already computed then return it
      	if (memo[n] != -1) 
          	return memo[n];
      	
      	// Any positive number n, can be represented 
      	// as sum of 1*1 + 1*1 .... n times
    	// so we can initialise count with n
        int cnt = n; 
    
        // Go through all smaller numbers
        // to recursively find minimum
        for (int x = 1; x*x <= n; x++) {
        	cnt = min(cnt, 1 + minSquaresRec(n - x*x, memo));
        }
      	
      	// store the result of this problem 
      	// to avoid re computation
        return memo[n] = cnt;
    }
    
    int minSquares(int n) {
      
        // Memoization array to store the results
    	vector<int> memo(n + 1, -1);
    	return minSquaresRec(n, memo);
    }
};