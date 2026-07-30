class Solution {
public:
    int minimumPushes(string word) {
        int distinct = word.size();
        int ans = 0;
        while(distinct > 0){
            ans += distinct;
            distinct -= 8;
        }

        return ans;
    }
};