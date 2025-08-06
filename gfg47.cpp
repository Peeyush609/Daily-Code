class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int n = s.size();
        
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        int ans = 0;
        int largest = 0;
        for(int i = n - 1; i >= 0; i--){
            if(mpp[s[i]] >= largest){
                largest = mpp[s[i]];
                ans += mpp[s[i]];
            }
            else{
                ans -= mpp[s[i]];
            }
        }
        
        return ans;
    }
};