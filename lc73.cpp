class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;

        // SUM OF X AND Y SHOULD BE ODD, If ONE EVEN THEN OTHER ODD AND IF ONE ODD THEN OTHER EVEN

        long long odd_n = 0;
        long long even_n = 0;

        odd_n = n/2;
        even_n = n/2;
        
        if(n%2==1)  odd_n++;
        
        long long odd_m = 0;
        long long even_m = 0;

        odd_m = m/2;
        even_m = m/2;
        
        if(m%2==1)  odd_m++;

        return odd_n*even_m + odd_m*even_n;
    }
};