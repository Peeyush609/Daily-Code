class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;

        int ori = n;
        while(n > 0){
            int x = n % 10;
            sum += x;
            product *= x;
            // cout<<x;
            n = n / 10;
        }
   
        return (ori % (sum + product) == 0);
    }
};