class Solution {
public:
    bool invalid(int ans, int t){
        string s = to_string(ans);

        int product = 1;
        for(char c: s){
            product *= c - '0';
        }

        return product % t != 0;
    }

    int smallestNumber(int n, int t) {
        int ans = n;
        while(invalid(ans, t)){
            ans++;
        }
        return ans;
    }
};