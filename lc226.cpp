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

    TreeNode* fill(vector<int> nums, int l, int r){
        if(l > r)  return NULL;  

        int mid = (l + r) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);

        curr->left = fill(nums, l, mid - 1);
        curr->right = fill(nums, mid + 1, r);

        return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();

            while(n--){
                auto curr = q.front();
                q.pop();

                nums.push_back(curr->val);

                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
            }
        }
        // for(int x: nums)    cout<<x<<" ";

        sort(nums.begin(), nums.end());

        return fill(nums, 0, nums.size() - 1);
    }
};