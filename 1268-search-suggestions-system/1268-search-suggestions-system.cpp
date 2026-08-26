class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = searchWord.length();
        vector<vector<string>> ans(n);

        int l = 0;
        int r = products.size() - 1;

        for(int i = 0; i < n; i++){
            char c = searchWord[i];

            while(l <= r && (i >= products[l].size() || products[l][i] != c)){
                l++;
            }
            while(l <= r && (i >= products[r].size() || products[r][i] != c)){
                r--;
            }

            for(int k = l; k <= min(l + 2, r); k++){
                ans[i].push_back(products[k]);
            }
        }

        return ans;
    }
};