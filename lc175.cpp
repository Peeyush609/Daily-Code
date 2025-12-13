class Solution {
public:
    bool valid(string c, string b, bool poss){
        if(!poss)return false;

        if(b!= "electronics" && b != "grocery" && b != "pharmacy" && b != "restaurant"){
            return false;
        }    

        if(c.empty())return false;
        for(char x: c){
            if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ||(x >= '0' && x <= '9') || (x == '_')){
                continue;
            }
            else{
                return false;
            }
        }

        return true;
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n= code.size();

        vector<string> ans;

        map<char, vector<string>> mpp;
        for(int i = 0; i < n; i++){
            if(valid(code[i], businessLine[i], isActive[i])){
                mpp[businessLine[i][0]].push_back(code[i]);
            }
        }

        for(auto it: mpp){
            vector<string> v= it.second;
            sort(v.begin(), v.end());
            for(auto x: v){
                ans.push_back(x);
            }
        }

        return ans;
    }
};