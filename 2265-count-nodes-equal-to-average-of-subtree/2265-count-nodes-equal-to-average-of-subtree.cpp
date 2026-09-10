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
    int subtreeavg(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        int sum = 0;
        int count = 0;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            count++;
            sum += curr->val;

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }

        return sum/count;
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            int avg = subtreeavg(curr);

            if(curr->val == avg)    ans++;

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }

        return ans;
    }
};