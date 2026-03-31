class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string ans(n+m-1, '$');

        // processing all the 'T's
        int i = 0;
        while(i < n){
            if(str1[i] == 'T'){
                int it = i;
                int j = 0;
                while(j < m){
                    if(ans[it] != '$' && ans[it] != str2[j])  return "";
                    ans[it] = str2[j];
                    j++;
                    it++;
                }
            }
            i++;
        }

        // fil rem spaces with 'a'
        vector<bool> canchange(n + m - 1, false);
        for(int i = 0; i < n + m - 1; i++){
            if(ans[i] == '$'){
                canchange[i] = true;
                ans[i] = 'a';
            }
        }

        // now at last we have to check if we have to convert any a to b so false satisfies 
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){

                if(ans.substr(i, m) == str2){
                    // mtlb ab hume kuch change krna padega
                    // hume koi 1 a ko b krna hoga right se left me jis se vo alg hojaye or lexiographically smallest bhi hi

                    bool changed = false;
                    for(int k = i + m - 1; k >= i; k--){
                        if(canchange[k]){
                            ans[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if(!changed){
                        return "";//mtlb koi false wali string same hogi str2 ke
                    }
                }
            }
        }

        return ans;
    }
};