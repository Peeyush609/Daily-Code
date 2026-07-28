class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans;

        vector<int> char_freq(26, 0);
        for(char c: s){
            char_freq[c - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(char_freq[i] == 0)   continue;
            ans.insert(ans.end(),char_freq[i] / 2, ('a' + i));
            char_freq[i] %= 2;
        }

        string second_half = ans;
        reverse(second_half.begin(), second_half.end());

        for(int i = 0; i < 26; i++){
            if(char_freq[i] != 0){
                ans += 'a' + i;
            }
        }

        ans += second_half;

        return ans;
    }
};