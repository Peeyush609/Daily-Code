/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return the bottom view of 
    // the binary tree
    vector<int> bottomView(Node *root) {
    
        // if root is NULL, return empty vector
        if (!root) return {};
    
        // Unordered map to store <vertical_index,
        // root->data>
        unordered_map<int, int> hash;
    
        // Store the leftmost index to help in 
        // left-to-right traversal
        int leftmost = 0;
    
        // Queue for level order traversal with 
        // pair<Node*, vertical index>
        queue<pair<Node*, int>> q;
        
        // Push the root with vertical index 0
        q.push({root, 0});
    
        while (!q.empty()) {
    
            // Store q.front() in top variable
            auto top = q.front();
            q.pop();
    
            // Current node
            Node *curr = top.first;
            
            // Vertical index of the current node
            int ind = top.second;
    
            // Update the vertical index -> node data
            hash[ind] = curr->data;
    
            // Track the leftmost vertical index
            leftmost = min(ind, leftmost);
    
            // Traverse left child with vertical 
          	// index ind - 1
            if (curr->left) { 
                q.push({curr->left, ind - 1});
            }
            
            // Traverse right child with vertical 
          	// index ind + 1
            if (curr->right) { 
                q.push({curr->right, ind + 1});
            }
        }
    
        // Vector to store the final bottom view
        vector<int> ans;
    
        // Traverse each value in hash from 
        // leftmost to rightmost
        while (hash.find(leftmost) != hash.end()) {
            ans.push_back(hash[leftmost++]);
        }
    
        return ans;
    }
};