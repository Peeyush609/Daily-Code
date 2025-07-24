class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int leftmost = n;
        for(int x: right){
            leftmost = min(leftmost, x);
        }
        
        int rightmost = 0;
        for(int x: left){
            rightmost = max(rightmost, x);
        }
        
        return max(n - leftmost, rightmost);
    }
};