class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;

        for(int i = 0; i < n; i += k){
            string t = s.substr(i, min(k, n));
            if(t.size() < k){
                t += string(k - t.size(), fill);
            }
            ans.push_back(t);
        }
        return ans;
    }
};