class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        int maxIdx = n - 1;  // index of max char from right
        int left = -1, right = -1;
        
        // Traverse from right to left
        for(int i = n - 2; i >= 0; i--){
            if(s[i] < s[maxIdx]){
                left = i;
                right = maxIdx;
            }
            else if(s[i] > s[maxIdx]){
                maxIdx = i;
            }
        }
        
        // If we found a valid swap
        if(left != -1){
            swap(s[left], s[right]);
        }
        
        return s;
    }
};
