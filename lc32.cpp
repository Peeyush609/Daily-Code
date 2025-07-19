class Solution {
public:
    bool check(string s, unordered_set<string> &mpp){

        vector<int> slash;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '/'){
                slash.push_back(i);
            }
        }

        for(int x: slash){
            string sub = s.substr(0, x);
            if(mpp.count(sub)){
                return true;
            }
        }
        return false;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());

        unordered_set<string> mpp;
        vector<string> ans;

        for(string s: folder){
            bool present = check(s, mpp);
            if(!present){
                ans.push_back(s);
                mpp.insert(s);
            }
        }

        return ans;
    }
};