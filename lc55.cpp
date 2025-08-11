class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        for(int i = 0; i < 30; i++){
            if((n & (1 << i)) != 0){
                powers.push_back((1<<i));
            }
        }

        vector<int> ans;
        int mod = 1000000007;
        for(auto q: queries){
            long long res = 1;
            for(int i = q[0]; i <= q[1]; i++){
                res = (res*powers[i]) % mod;
            }
            ans.push_back(res % mod);
        }
        return ans;
    }
};