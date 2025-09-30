class Solution {
  public:
    string decimal2binary(int x, int n){

        string ans = "";
    
        while(x>0){
            int a=x%2;
            ans.push_back('0'+a);
            x=x/2;
        }
        
        while(ans.length() < n){
            ans += '0';
        }
    
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
    
    vector<string> binstr(int n) {
        // code here
        vector<string> ans;
        
        for(int i = 0; i < (1<<n); i++){
            ans.push_back(decimal2binary(i, n));
        }
        return ans;
    }
};