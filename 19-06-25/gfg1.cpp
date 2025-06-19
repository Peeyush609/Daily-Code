class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string lower;
        string upper;
        
        for(char c: s){
            if(islower(c)){
                lower += c;
            }
            else{
                upper += c;
            }
        }
        
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        
        string ans;
        int i = 0;
        int j= 0;
        for(char c:s){
            if(islower(c)){
                ans += lower[i];
                i++;
            }
            else{
                ans += upper[j];
                j++;
            }
        }
        return ans;
    }
    
};