class Solution {
public:
    string next(string s){
        string ans;
        for(char c:s){
            if(c == 'z')    ans += 'a';
            else            ans += c + 1;
        }
        return ans;
    }

    char kthCharacter(int k) {
        string s = "a";

        while(s.size() < k){
            string temp = next(s);
            s += temp;
        }

        return s[k-1];//0 based indexing
    }
};