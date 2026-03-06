class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        int c = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '1'){
                while(s[i] == '1'){
                    i++;
                }
                c++;
            }
            else i++;
        }

        return c <= 1;
    }
};