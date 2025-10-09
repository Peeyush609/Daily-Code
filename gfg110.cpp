/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void fun(Node *node, vector<int> &res)
    {
        if (node == nullptr)
            return;
    
        // First we traverse left subtree
        fun(node->left, res);
    
        // After visiting left, traverse right subtree
        fun(node->right, res);
    
        // now we visit node
        res.push_back(node->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        fun(root, ans);
        return ans;
    }
    
        
};