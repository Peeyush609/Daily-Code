class Solution {
  public:
    void fun(int n, int k, vector<int>& curr, vector<vector<int>>& ans, int i){
        if (n == 0 && k == 0) {   // valid combination
            ans.push_back(curr);
            return;
        }
        if (n < 0 || k < 0 || i > 9) return;  // prune

        // take i
        curr.push_back(i);
        fun(n - i, k - 1, curr, ans, i + 1);
        curr.pop_back();

        // skip i
        fun(n, k, curr, ans, i + 1);
    }
  
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<int> curr;
        vector<vector<int>> ans;
        fun(n, k, curr, ans, 1);
        
        return ans;
    }
};