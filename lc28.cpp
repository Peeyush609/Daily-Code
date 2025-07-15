class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }

    bool isValid(string word) {
        int n = word.size();

        if(n < 3)   return false;
        bool vowel = false;
        bool consonant = false;

        for(char c: word){
            if(isvowel(tolower(c))){
                vowel = true;
            }
            else if(isalpha(c)){
                consonant = true;
            }
            else if(isalnum(c)){
                continue;
            }
            else{
                // special char
                return false;
            }
        }

        return (vowel && consonant);
    }
};