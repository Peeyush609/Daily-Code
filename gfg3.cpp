class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        
        int ans = 0;
        vector<int> police;
        vector<int> theives;
        
        for(int i = 0; i < n; i++){
            char c = arr[i];
            if(c == 'P')    police.push_back(i);
            else            theives.push_back(i);
        }
        
        int p = 0; 
        int t = 0;
        while(p < police.size() && t < theives.size()){
            if(abs(police[p] - theives[t]) <= k){
                p++;
                t++;
                ans++;
            }
            else if(theives[t] < police[p]){
                t++;
            }
            else{
                p++;
            }
            
        }
        
        
        return ans;
    }
};