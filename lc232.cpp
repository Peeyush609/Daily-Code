class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        // Ensure a is the longer string
        if (n < m) {
            swap(a, b);
            swap(n, m);
        }

        // Pad b with leading zeroes
        b = string(n - m, '0') + b;


        //add
        //0 + 0 = 0
        //1 + 0 = 1
        //0 + 1 = 1;
        //1 + 1 = 0 : carry = 1

        string ans;
        int i = n - 1;
        int carry = 0;
        while(i >= 0){
            int bitA = a[i] - '0';
            int bitB = b[i] - '0';

            int sum = bitA + bitB + carry;
            ans += (sum % 2) + '0';
            carry = sum / 2;

            i--;
        }
        if(carry)   ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};