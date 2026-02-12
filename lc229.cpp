class Solution {
public:
    bool valid(vector<int> freq){
        int fr = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                fr = freq[i];
                break;
            }
        }

        for(int x: freq){
            if(x != 0 && x != fr)   return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                if(valid(freq)){
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};