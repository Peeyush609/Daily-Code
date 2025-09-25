class Solution {
public:
    //space optimization
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, 0);

        for(int j = 0; j < n; j++){
            prev[j] = triangle[n-1][j]; 
        }

        for(int i = n - 2; i >=0; i--){
            vector<int> temp(n, 0);
            for(int j = i; j >=0 ; j--){

                int left = triangle[i][j] + prev[j];
                int right = triangle[i][j] + prev[j+1];

                temp[j]= min(left, right);
            }
            prev = temp;
        }

        return prev[0];
    }
};