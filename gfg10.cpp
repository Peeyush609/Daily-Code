class Solution {
  public:
  
    int count(int mid, vector<int>& nums, int w, int n){
        
        int ans = 0;
        int add = 0;
        vector<int> diff(n + 2, 0);
        
        for(int i = 0; i < n; i++){
            add += diff[i];
            int curr = nums[i] + add; 
            
            if(curr < mid){
                int d = mid - curr;
                
                ans += d;
                
                add += d;
                
                if(i + w < n)   diff[i + w] -= d;
            }
        }
        
        return ans;
    }
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int n = arr.size();
        
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        
        int ans = low;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int c = count(mid, arr, w, n);
            
            if(c <= k){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};