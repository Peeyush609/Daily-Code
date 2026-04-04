class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int m = n / rows;
        if(n == 0)  return "";
        string ans = "";

        for(int i = 0; i < m; i++){
            for(int j = i; j < n; j += (m + 1)){
                ans += encodedText[j];
            }
        }
        int ind = 0;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] != ' '){
                ind = i;//record the last not space char
            }
        }

        return string(ans.begin(), ans.begin() + ind + 1);
    }
};