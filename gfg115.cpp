/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        int ans = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                if(q.front()->data >= l && q.front()->data <= r){
                    ans += q.front()->data;
                }
                
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                
                q.pop();
            }
        }
        
        return ans;
    }
};
