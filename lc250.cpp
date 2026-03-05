class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // 1st char should be one 1
        int start_one = 0;
        bool one = true;
        for(int i = 0; i < n; i++){
            if(one && s[i] != '1')  start_one++;
            else if(!one && s[i] != '0')    start_one++;
            one = !one;
        }
        // 1st char should be 0
        int start_zero = 0;
        one = false;
        for(int i = 0; i < n; i++){
            if(one && s[i] != '1')  start_zero++;
            else if(!one && s[i] != '0')    start_zero++;
            one = !one;
        }

        cout<<start_one<<" "<<start_zero;
        return min(start_one, start_zero);
    }
};