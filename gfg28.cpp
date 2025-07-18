class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if(n < 3)   return n;
        int ans = 0;
        
        if(n % 2 == 0){
            ans =  (n - 1)*(n-2)*(n-3);
            if(n % 3 != 0){
                ans = (n)*(n-1)*(n-3);  
            }
        }
        else{
            ans =  n*(n-1)*(n-2);
        }
        
        return ans;
    }
};