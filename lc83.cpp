class Solution {
public:
    bool check(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);

        for(char c: sa){
            if(c == '0')    return false;
        }
        for(char c: sb){
            if(c == '0')    return false;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a < n; a++){
            if(check(a, n - a)){
                return {a, n-a};
            }
        }

        // will never reach here
        return {};
    }
};