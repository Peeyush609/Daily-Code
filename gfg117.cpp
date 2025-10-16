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
    Node* removekeys(Node* root, int l, int r) {
    
        if (root == nullptr) return nullptr;
        Node* left = removekeys(root->left, l, r);
        Node* right = removekeys(root->right, l ,r);
        
        // If curr node lies in the range, update its 
        // left and right nodes and return curr node.
        if (root->data>=l && root->data<=r) {
            root->left = left;
            root->right = right;
            
            return root;
        }
        
        // If current node is less than range,
        // then return the updated right subtree.
        else if (root->data<l) {
            return right;
        }
        
        // Else return the updated left subtree.
        else 
            return left;
    }
};