class Solution {
public:
    int maxFreqSum(string s) {
        int maxi1 = 0;
        int maxi2 = 0;

        unordered_map<char, int> mpp;
        for(char c: s){
            mpp[c]++;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                maxi1 = max(maxi1, mpp[c]);
            }
            else{
                maxi2 = max(maxi2, mpp[c]);
            }
        }

        return maxi1 + maxi2;
    }
};