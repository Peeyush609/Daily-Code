/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void transformTree(Node *root) {
        // code here
        queue<Node*> q;
        q.push(root);
        
        vector<int> nums;
        
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
        
        sort(nums.rbegin(), nums.rend());
        unordered_map<int, int> mpp;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]] = sum;
            sum += nums[i];
            
        }
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                Node* curr = q.front();
                curr->data = mpp[curr->data];
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                q.pop();
            }
        }
    }
};