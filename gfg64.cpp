class Solution {
  public:
  
    int count(int mid, vector<int>& arr){
        int c = 1; 
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(sum + arr[i] > mid){
                c++;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
        
        return c;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k > n) return -1;
        
        int low = *max_element(arr.begin(), arr.end()); 
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int c = count(mid, arr);
            if(c <= k){   // ✅ valid allocation
                ans = mid;
                high = mid - 1; // try for smaller maximum
            }
            else{
                low = mid + 1;  // too small, need more students
            }
        }
        
        return ans;
    }
};
