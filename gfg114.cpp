//Maximum Non-Adjacent Nodes Sum



/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    // method to return the maximum 
    // sum rooted at the node 'node'
    int getMaxSumUtil(Node* node, unordered_map<Node*, int>& memo) {
        if (node == NULL) return 0;
    
        if (memo.find(node) != memo.end()) {
            return memo[node];
        }
    
        // Calculate the maximum sum 
        // including the current node
        int include = node->data;
    
        if (node->left != NULL) {
            include += getMaxSumUtil(node->left->left, memo) +
                       getMaxSumUtil(node->left->right, memo);
        }
    
        if (node->right != NULL) {
            include += getMaxSumUtil(node->right->left, memo) +
                       getMaxSumUtil(node->right->right, memo);
        }
    
        // Calculate the maximum sum 
        // excluding the current node
        int exclude = getMaxSumUtil(node->left, memo) +
                      getMaxSumUtil(node->right, memo);
    
        memo[node] = max(include, exclude);
        return memo[node];
    }
    
    int getMaxSum(Node* root) {
        unordered_map<Node*, int> memo;
       
        return getMaxSumUtil(root, memo);
    }
};