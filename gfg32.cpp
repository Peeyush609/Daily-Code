class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        unordered_set<int> ss;
        for(int x: arr){
            if(x > 0){
                ss.insert(x);
            }
        }
        
        for(int i = 1; i < 1e6; i++){
            if(!ss.count(i)){
                return i;
            }
        }
        
        return -1; //wil never reach here
    }
};