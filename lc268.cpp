class Solution {
public:

    vector<vector<int>> check(string word){
        int n = word.size();
        vector<vector<int>> lcp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            if(word[i] == word[n - 1]){
                lcp[i][n - 1] = 1;
            }
        }

        for(int j = 0; j < n; j++){
            if(word[j] == word[n - 1]){
                lcp[n-1][j] = 1;
            }
        }

        for(int i = n - 2; i>= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                if(word[i] == word[j]){
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                }
                else{
                    lcp[i][j] = 0;
                }
            }
        }

        return lcp;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string word(n, '$');

        for(int i = 0; i < n; i++){
            
            vector<bool> forbid(26, false);
            for(int j = 0; j < i; j++){
                if(lcp[j][i] != 0){
                    word[i] = word[j];
                    break;
                }
                else{
                    forbid[word[j] - 'a'] = true;
                }
            }

            if(word[i] == '$'){

                for(int idx = 0; idx < 26; idx++){
                    if(!forbid[idx]){
                        word[i] = idx + 'a';
                        break;
                    } 
                }

                if(word[i] == '$')  return "";
            }
        }

        return check(word) == lcp ? word : "";
    }
};