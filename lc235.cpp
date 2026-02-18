class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n > 0){
            int curr;
            if(n % 2 == 0){
                curr = 0;
            }
            else    curr = 1;

            if(curr == prev)    return false;
            n = n / 2;
            prev = curr;
        }
        return true;
    }
};