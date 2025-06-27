class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();

        int zeroes = 0;
        for(int i = n - 1 ; i >= 0; i--){
            if(s[i] == '0'){
                zeroes++;
            }
        }

        int power = 0;
        int len = zeroes;
        long long sum = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1'){
                if (power < 31) { // To prevent overflow when shifting
                    if ((sum + (1LL << power)) <= k) {
                        sum += (1LL << power);
                        len++;
                    }
                }
            }
            power++;
        }

        return len;
    }
};
