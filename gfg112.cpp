/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Returns the maximum path 
    // sum in the subtree with the current node as an endpoint. 
    int findMaxSumRec(Node* root, int& res) {
      
        if (root == NULL)
            return 0;
    
        // Calculate maximum path sums for left and right subtrees
        int l = max(0, findMaxSumRec(root->left, res));
        int r = max(0, findMaxSumRec(root->right, res));
    
        // Update 'res' with the maximum path
        // sum passing through the current node
        res = max(res, l + r + root->data);
    
        return root->data + max(l, r);
    }
    
    // Returns maximum path sum in tree with given root
    int findMaxSum(Node* root) {
        int res = root->data;
    	
      	// Compute maximum path sum and store it in 'res'
        findMaxSumRec(root, res);
      
        return res;
    }
};