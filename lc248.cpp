class Solution {
public:
    string inverse(string s){
        string ans;
        for(char c:s){
            if(c == '0')    ans += '1';
            else            ans += '0';
        }
        return ans;
    }

    char findKthBit(int n, int k) {
        string prev = "0";
        string s = prev;
        while(n > 1){
            string t = inverse(prev);
            reverse(t.begin(), t.end());
            s = prev + '1' + t;
            prev = s;

            n--;
        }

        return s[k-1];
    }
};