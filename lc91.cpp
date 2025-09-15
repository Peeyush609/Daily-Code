class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;

        unordered_set<char> ss;
        for(char c: brokenLetters){
            ss.insert(c);
        }
        
        bool yes = true;
        for(char c: text){
            if(c == ' '){
                if(yes) ans++;
                yes = true;
            }
            if(ss.count(c)){
                yes = false;
            }
        }
        if(yes) ans++;
        return ans;
    }
};