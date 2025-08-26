class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        int ans = 0;
        long long maxi = 0;
        for(auto it: dimensions){
            int l = it[0];
            int w = it[1];

            long long diag = l*l + w*w;
            if(diag > maxi){
                ans = l*w;
                maxi = diag;
            }
            else if(diag == maxi){
                ans = max(ans, l*w);
            }
        }
        return ans;
    }
};