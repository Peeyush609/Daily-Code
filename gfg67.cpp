class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        int i = 0; 
        int j = 0;
        
        while(j < m){
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
        
        return i == n;
    }
};