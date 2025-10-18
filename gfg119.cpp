/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findMedian(Node* root) {
        // Code here
        vector<int> nums;
        queue<Node*> q;
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* curr = q.front();
                
                nums.push_back(curr->data);
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                q.pop();
            }
        }
        
        sort(nums.begin(), nums.end());
        int mid = (nums.size() + 1) / 2;
        return nums[mid - 1];//median
    }
};