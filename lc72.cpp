class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        unordered_map<int, vector<int>> mpp;//contains the diagonals

        int n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int diff = i - j;
                mpp[diff].push_back(grid[i][j]);
            }
        }

        //now sort diagonals according to condition
        for(auto& [a, b] : mpp){
            //yaha pe ulta store karo kyuki hum vector me peeche se nikaalenge
            
            if(a >= 0){
                //sort in asc order
                sort(b.begin(), b.end());
            }
            else{
                //sort in dec order
                sort(b.rbegin(), b.rend());
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int diff = i - j;
                grid[i][j] = mpp[diff].back();
                mpp[diff].pop_back();
            }
        }

        return grid;
    }
};