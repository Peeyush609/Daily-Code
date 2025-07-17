/*

Power of k in factorial of n
	
Given two positive integers n and k, determine the highest value of x such that kx divides n! (n factorial) completely (i.e., n % (kx) == 0).

Examples :

Input: n = 7, k = 2
Output: 4
Explanation: 7! = 5040, and 24 = 16 is the highest power of 2 that divides 5040.

Input: n = 10, k = 9
Output: 2
Explanation: 10! = 3628800, and 9² = 81 is the highest power of 9 that divides 3628800.

Constraints:
1 ≤ n ≤ 105
2 ≤ k ≤ 105

*/


class Solution {
  public:
  
    // Function to count power of prime p in n!
    int countPowerInFactorial(int n, int p) {
        int count = 0;
        while (n) {
            n /= p;
            count += n;
        }
        return count;
    }
    
    // Main function to compute highest power x such that k^x divides n!
    int maxKPower(int n, int k) {
        int result = INT_MAX;
    
        // Step 1: Prime factorization of k
        for (int i = 2; i * i <= k; ++i) {
            if (k % i == 0) {
                int powerInK = 0;
                while (k % i == 0) {
                    k /= i;
                    ++powerInK;
                }
    
                // Step 2: Count power of i in n!
                int powerInFact = countPowerInFactorial(n, i);
    
                // Step 3: Calculate how many times this prime power fits
                result = min(result, powerInFact / powerInK);
            }
        }
    
        // If k is still > 1, it's a prime itself
        if (k > 1) {
            int powerInFact = countPowerInFactorial(n, k);
            result = min(result, powerInFact); // Since power in k is 1
        }
    
        return result;
    }
};