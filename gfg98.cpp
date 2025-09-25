class Solution {
  public:
    string decimal2binary(int x){
        if(x==0)     return "0";
    
        string ans;
    
        while(x>0){
            int a=x%2;
            ans.push_back('0'+a);
            x=x/2;
        }
    
        reverse(ans.begin(), ans.end());
    
        return ans;
    }
  
    vector<string> generateBinary(int n) {
        // code here
        vector<string> ans;
        for(int i = 1; i <= n; i++){
            ans.push_back(decimal2binary(i));
        }
        return ans;
    }
};