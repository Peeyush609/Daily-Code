class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;


        for(char c = 'A'; c <= 'Z'; c++){

            int i = 0;
            int j = 0;
            unordered_map<char, int> mpp;
            while(i < n && j < n){
                mpp[s[j]]++;
                while((j - i + 1 - mpp[c]) > k){
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0){
                        mpp.erase(s[i]);
                    }                
                    i++;
                }

                ans = max(ans, j - i + 1);
                j++;
            }
        }

        return ans;
    }
};