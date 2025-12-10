class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1000000007;
        int n = complexity.size();

        // if 1st is not smallest then 0 is answer
        for(int i = 1; i < n; i++){
            if(complexity[i] <= complexity[0]){
                return 0;
            }
        }

        // else 1st is 1st in order and then there are n-1 ! options or permutations
        long long ans = 1;
        for (int i = 2; i <= n - 1; ++i) {
            ans = (ans * i) % MOD;
        }
        return (int)ans;
    }
};