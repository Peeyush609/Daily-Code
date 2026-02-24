/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, string s){
        s += root->val + '0';

        // leaf node
        if(!root->left && !root->right){
            int val = 0;
            int n = s.size();
            for(int i = 0; i < n; i++){
                if(s[i] == '1'){
                    val += (1 << (n - i - 1));
                }
            }
            return val;
        }
        
        int ans = 0;
        if(root->left)  ans += solve(root->left, s);
        if(root->right)  ans += solve(root->right, s);
        return ans;
    }

    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL)    return 0;
        return solve(root, "");
    }
};