class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        vector<int> small_freq(26, 0);
        for(char c: word){
            if(islower(c)){
                small_freq[c - 'a']++;
            }
        }

        vector<int> small_curr(26, 0);
        unordered_set<int> ss;
        unordered_set<int> caps;

        for(char c: word){
            if(islower(c)){
                small_curr[c - 'a']++;
            }
            else{
                if(caps.count(c))   continue;
                caps.insert(c);
                if(small_curr[c - 'A'] > 0 && small_curr[c - 'A'] == small_freq[c - 'A']){
                    cout<<c<<endl;
                    ss.insert(c);
                }
            }
        }

        return (int)ss.size();
    }
};