class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for(char c: word){
            count[c - 'a']++;
        }

        sort(count.rbegin(), count.rend());
        int ans = 0;
        int cnt = 0;
        int val = 1;
        for(auto f: count){
            if(cnt != 0 && cnt % 8 == 0)  val++;
            ans += f*val;
            cnt++;
        }

        return ans;
    }
};
