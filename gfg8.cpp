class Solution {
  public:
  
    int upper_bound(int x, vector<int>& b){
        int low = 0;
        int high = b.size() - 1;
        
        int ans = 0;
        while(low <= high){
            int mid = (high + low)/2;
            
            if(b[mid] <= x){
                low = mid + 1;
                ans = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
  
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        sort(b.begin(), b.end());
        
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = upper_bound(a[i], b);
        }
        return ans;
    }
};