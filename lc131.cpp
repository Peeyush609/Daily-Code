class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int ans = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(char c: bank[i]){
                if(c == '1')    curr++;
            }
            if(curr > 0){
                ans += prev * curr;
                prev = curr;
            }     
        }

        return ans;
    }
};