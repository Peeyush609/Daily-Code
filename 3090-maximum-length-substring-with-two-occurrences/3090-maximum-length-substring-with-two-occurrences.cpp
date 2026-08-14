class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> freq(26, 0);

        int i = 0;
        int j = 0;

        while(j < n){
            freq[s[j] - 'a']++;
            while(freq[s[j] - 'a'] > 2){
                freq[s[i] - 'a']--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};