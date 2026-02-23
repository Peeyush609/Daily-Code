class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        unordered_set<string> ss;
        for(int i = 0; i <= n - k; i++){
            ss.insert(s.substr(i, k));
        }

        cout<<ss.size();

        return ss.size() >= (1<<k);
    }
};