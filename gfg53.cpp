class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        sort(prices.begin(), prices.end());
        
        int mini = 0;
        int i = 0;
        int count = 0;
        while(i < n && count < n){
            mini += prices[i];
            
            count += k + 1;
            i++;
        }
        
        int maxi = 0;
        i = n - 1;
        count = 0;
        
        while(i >= 0 && count < n){
            maxi += prices[i];
            count += k + 1;
            i--;
        }
        
        return {mini, maxi};
        
    }
};