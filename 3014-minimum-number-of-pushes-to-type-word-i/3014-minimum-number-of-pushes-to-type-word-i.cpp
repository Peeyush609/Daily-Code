class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<int> ss;
        for(char c: word){
            ss.insert(c);
        }

        int distinct = ss.size();
        int ans = 0;
        while(distinct > 0){
            ans += distinct;
            distinct -= 8;
        }

        return ans;
    }
};