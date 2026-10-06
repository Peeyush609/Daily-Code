class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;

        int o = 0;

        for(char c : s){
            if(c == ')'){
                if(o > 0){
                    o--;
                }
                else{
                    ans++;
                }
            }
            else{
                o++;
            }
        }
        ans += o;
        return ans;
    }
};