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
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
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
        map<int, vector<int>> mpp;
        // diff-> elements
        for(int x: nums){
            mpp[abs(x-target)].push_back(x);
        }
        
        // for(auto it: mpp){
        //     cout<<it.first<<" -> ";
        //     for(int x: it.second){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> ans;
        for(auto it: mpp){
            for(int x: it.second){
                if(ans.size() == k) break;
                ans.push_back(x);
            }
            if(ans.size() == k) break;
        }
        return ans;
    }
};