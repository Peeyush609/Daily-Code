/*

Nine Divisors
	
Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.

Examples :

Input: n = 100
Output: 2
Explanation: Numbers which have exactly 9 divisors are 36 and 100.

Input: n = 200
Output: 3
Explanation: Numbers which have exactly 9 divisors are 36, 100, 196. 

Constraints:
1 ≤ n ≤ 109

Expected Complexities
Time Complexity: O(sqrt(n) * log(log(sqrt(n))))
Auxiliary Space: O(sqrt(n))

*/


class Solution {
  public:
    long long power(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {  // If exponent is odd
                result *= base;
            }
            base *= base;
            exp /= 2;
        }
        return result;
    }

    
    vector<int> seive(int n){
        vector<bool> prime(n, true);
        vector<int> ans;
        
        for(int i = 2; i < n; i++){
            if(prime[i]){
                for(int j = i*i; j < n; j += i){
                    prime[j] = false;
                }
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
    int countNumbers(int n) {
        // Code Here
        
        // If X = p1^a1 * p2^a2 * ... * pk^ak
        // Then total divisors = (a1 + 1) * (a2 + 1) * ... * (ak + 1)

        // to get exact 9 divisors
        // Type A: p^8 (one prime to the 8th power)
        // Type B: p1^2 * p2^2 (product of two distinct primes squared)
        
        vector<int> primes = seive(sqrt(n));
        
        int count = 0;
        
        for(int x : primes){
            long long prime_power8 = power(x, 8);
            if(prime_power8 < n){
                count++;
            }
            else{
                break;
            }
        }
        
        
        for(int i = 0; i < primes.size(); i++){
            for(int j = i+1; j < primes.size(); j++){
                long long num = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if(num <= n) count++;
                else break; // further j will be bigger
            }
        }

        
        
        return count;
    }
};