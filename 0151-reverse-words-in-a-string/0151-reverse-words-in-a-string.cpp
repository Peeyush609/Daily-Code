class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        vector<string> vec;
        int i = 0;  

        string curr;
        while(i < n){
            if(s[i] ==' '){
                while(s[i] == ' '){
                    i++;
                }
                if(!curr.empty()){
                    vec.push_back(curr);
                    curr = "";
                }    
            }
            else{
                curr += s[i];
                i++;
            }
        }
        if(!curr.empty())   vec.push_back(curr);

        string ans;
        for(int i  = vec.size() - 1; i >= 0; i--){
            ans += vec[i];
            ans += ' ';
        }

        ans.pop_back();


        for(string x: vec){
            cout<<x<<endl;
        }

        return ans;
    }
};