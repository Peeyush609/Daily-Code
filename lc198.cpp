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
    int maxLevelSum(TreeNode* root) {
        int level = 1;

        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
        int ans = -1;

        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode* curr = q.front();
                sum += curr->val;
                if(curr->left)   q.push(curr->left);
                if(curr->right)   q.push(curr->right);
                
                q.pop();
            }
            if(sum > maxi){
                ans = level;
                maxi = sum;
            }
            level++;
        }

        return ans;
    }
};