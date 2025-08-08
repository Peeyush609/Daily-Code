//Brute force
class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n = s.size();
        
        unordered_set<string> suffixes;
        for(int i = n - 1; i > 0; i--){
            suffixes.insert(s.substr(i, n - i));
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            string prefix = s.substr(0, i+1);
            if(suffixes.count(prefix)){
                ans = i+1;
            }
        }
        
        return ans;
    }
};



//OPtimal approach
class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int n = s.size();
        
        vector<int> lps(n, 0);
        
        int i = 0;
        int j = 1;
        
        while(j < n){
            if(s[i] == s[j]){
                lps[j] = i + 1;
                
                i++;
                j++;
            }
            else{
                if(i == 0){
                    j++;
                }
                else{
                    i = lps[i - 1];//dont increaase j check once again for the new i
                }
            }
        }
        
        return lps[n - 1];
    }
};