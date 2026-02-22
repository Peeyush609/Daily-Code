class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int prev = -1;
        int ind = 0;
        while(n > 0){
            if(n % 2 == 1){
                if(prev != -1)    ans = max(ans, ind - prev);
                prev = ind;
            }
            n = n / 2;
            ind ++;
        }

        return ans;
    }
};