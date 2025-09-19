class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int n = s.size();
        
        int open = 0;
        int closed = 0;
        for(char c:s){
            if(c == '(')    open++;
            else{
                if(open > 0)    open--;
                else            closed++;
            }
        }
        
        return open + closed;
    }
};