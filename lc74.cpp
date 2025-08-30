class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> present;
        
        //for distinct rows
        for(int i = 0; i < 9; i++){
            present.assign(10, false);
            for(int j = 0; j < 9; j++){
                char c = board[i][j];

                if(c != '.'){
                    if(present[c - '0']){
                        // cout<<c<<endl;
                        return false;
                    }
                    else        present[c - '0'] = true;
                }
            }
        }

        //for distinct columns
        for(int i = 0; i < 9; i++){
            present.assign(10, false);
            for(int j = 0; j < 9; j++){
                char c = board[j][i];

                if(c != '.'){
                    if(present[c - '0']){
                        // cout<<c<<endl;
                        return false;
                    }    
                    else        present[c - '0'] = true;
                }
            }
        }

        //for distinct 3*3 sub boxes
        vector<pair<int, int>> v = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};

        for(auto [x, y] : v){
            present.assign(10, false);
            for(int i = x; i < x + 3; i++){
                for(int j = y; j < y + 3; j++){
                    char c = board[j][i];

                    if(c != '.'){
                        if(present[c - '0']){
                            cout<<c<<endl;
                            return false;
                        }    
                        else        present[c - '0'] = true;
                    }
                }
            }
        }
        

        return true;
    }
};