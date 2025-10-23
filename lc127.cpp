class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        while(s.size() != 2){
            string temp;
            for(int i = 0; i < s.size() - 1; i++){
                int v = (s[i] - '0' + s[i + 1] - '0' + 10) % 10;
                temp.push_back(v + '0');
            }
            s = temp;
        }

        return s[0] == s[1];
    }
};