class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans = {{1}};
        vector<int> prev;

        for (int i = 1; i < numRows; i++)
        {
            vector<int> curr;
            curr.push_back(1);
            for (int j = 0; j < (int)prev.size() - 1; j++){
                curr.push_back(prev[j] + prev[j + 1]);
            }
            curr.push_back(1);
            ans.push_back(curr);
            
            prev = curr;
        }

        return ans;
    }
};