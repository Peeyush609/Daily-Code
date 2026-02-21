class Solution {
public:

    int no_of_set_bits(int i){
        int s = 0;
        while(i > 0){
            s += i%2;
            i = i/2;
        }
        return s;
    }
    bool prime(int x){
        if(x <= 1)  return false;
        for(int i = 2; i*i <= x; i++){
            if(x % i == 0)  return false;
        }
        return  true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++){
            int set_bits = no_of_set_bits(i);
            if(prime(set_bits)){
                ans++;
            }
        }

        return ans;
    }
};