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

    unordered_map<TreeNode*, int> mpp;
    int maxd = 0;

    void depth(TreeNode* root, int d){

        if(!root){
            return;
        }

        maxd = max(maxd, d);
        mpp[root] = d;
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }


    TreeNode* LCA(TreeNode* node){
        if(node == NULL || mpp[node] == maxd){
            return node;
        }

        TreeNode* left = LCA(node->left);
        TreeNode* right = LCA(node->right);

        if(left && right){
            return node;
        }

        return left != NULL ? left : right;
    }


    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root, 0);

        return LCA(root);
    }
};