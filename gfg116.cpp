/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int> nodes;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* curr = q.front();
                nodes.push_back(curr->data);
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                q.pop();
            }
        }
        
        if(nodes.size() < k)  return -1;
        sort(nodes.begin(), nodes.end());
        return nodes[k - 1];
    }
};