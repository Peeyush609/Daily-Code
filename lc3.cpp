class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();

        vector<int> freq(26, 0);

        for(char c: word){
            freq[c - 'a']++;
        }

        int ans = INT_MAX;
        for(int i = 0; i < 26; i++){
            int del = 0;
            int fi = freq[i];
            for(int j = 0; j < 26; j++){
                if(j == i)  continue;

                int fj = freq[j];
                if(fj < fi){
                    del += fj;
                }
                else if(abs(fj - fi) > k){
                    del += abs(fj - fi - k);
                }
            }
            ans = min(ans, del);
        }
        return ans;
        
    }
};