class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        // this is similar to the qsn like longest subarray with max 2 unique numbers

        unordered_map<int, int> mpp;
        int i = 0;
        int j = 0;
        int ans = 0;

        while(j < n){
            mpp[fruits[j]]++;
            while(mpp.size() > 2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};