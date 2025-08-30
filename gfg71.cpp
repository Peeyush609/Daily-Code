class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        for(int c = 0; c < n; c++){
            // for celeb he shouldnt know any other person
            bool celeb = true;
            for(int j = 0; j < n; j++){
                if(mat[c][j] == 1 && c != j){
                    celeb = false;
                    break;
                }
            }
            if(!celeb)  continue;
            
            for(int i = 0; i < n; i++){
                if(mat[i][c] != 1){
                    celeb = false;
                    break;
                }
            }
            
            if(celeb)    return c;
        }
        
        return -1;
    }
};