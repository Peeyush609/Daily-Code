class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n + 1, 0);
        for(int i = 0; i < n; i++){
            ans[i + 1] = digits[i];
        }

        int carry = 1;
        for(int i = n; i >= 1; i--){
            if(carry + digits[i - 1] <= 9){
                ans[i] += carry;
                carry = 0;
                break;
            }
            else{
                ans[i] = 0;
            }
        }
        if(carry == 0) ans.erase(ans.begin());
        else    ans[0] = 1;
        return ans;
    }
};