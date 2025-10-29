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

    int binary2decimal(string x ){
        int ans=0;
        int len=x.length();
        int mul=1;
        for(int i=len-1; i>=0; i--){
            if(x[i]=='1'){
                ans+=mul;

            }
            mul=2*mul;
        }

        return ans;
    }

    int smallestNumber(int n) {
        string s = decimal2binary(n);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') s[i] = '1';
        }

        return binary2decimal(s);
    }
};