class Solution {
public:
    bool vowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u'||
            c == 'A' || c == 'E' || c == 'I' || c =='O' || c == 'U'){
                return true;
            }
        return false;
    }
    string sortVowels(string s) {
        vector<char> v;

        for(char c: s){
            if(vowel(c)){
                v.push_back(c);
            }
        }

        sort(v.begin(), v.end());

        for(char c: v){
            cout<<c<<" ";
        }

        int ind = 0; //for vowels
        string ans;
        for(char c : s){
            if(vowel(c)){
                ans += v[ind++];
            }else{
                ans += c;
            }
        }

        return ans;
    }
};