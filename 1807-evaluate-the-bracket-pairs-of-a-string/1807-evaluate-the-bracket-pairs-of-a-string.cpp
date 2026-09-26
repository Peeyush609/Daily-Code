class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        string ans;

        unordered_map<string, string> mpp;
        for(auto it: knowledge){
            mpp[it[0]] = it[1];
        }

        int i = 0;
        while(i < n){
            if(s[i] == '('){
                i++;
                string key;
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                if(mpp.count(key)){
                    ans += mpp[key];
                }
                else{
                    ans += '?';
                }
                // i++;
            }else{
                ans += s[i];
            }
            i++;
        }

        return ans;
    }
};