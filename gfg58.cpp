class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        vector<vector<int>> temp;
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            int diff = abs(x - arr[i]);
            temp.push_back({diff, i});
        }
        
        sort(temp.begin(), temp.end());
        
        vector<int> temp2 = arr;
        for(int i = 0; i < n; i++){
            arr[i]= temp2[temp[i][1]];
        }

    }
};