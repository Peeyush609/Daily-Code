class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int n = s.size();
        
        string p;
        for(char c: s){
            if(isalnum(c)){
                if(c >= '0' && c <= '9'){
                    p += c;
                }
                else p += tolower(c);
            }
        }
        
        string rev = p;
        reverse(rev.begin(), rev.end());
        
        return rev == p;
    }
};