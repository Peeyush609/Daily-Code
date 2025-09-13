class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        int ans = 0;
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int xn = 1;
        int yn = 1;
        
        int i = 0;
        int j = 0;
        
        while(i < m - 1 && j < n - 1){
            if(x[i] >= y[j]){
                ans += x[i]*xn;
                yn++;
                i++;
            }
            else{
                ans += y[j]*yn;
                xn++;
                j++;
            }
        }
        
        while(i < m - 1){
            ans += x[i]*xn;
            yn++;
            i++;
        }
        
        while(j < n -1){
            ans += y[j]*yn;
            xn++;
            j++;
        }
        
        return ans;
    }
};
