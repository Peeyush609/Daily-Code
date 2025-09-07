// merge k sorted linked lists

// approach 1 : direct sort all the nums and make the list

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        vector<int> nums;
        for(auto t: arr){
            while(t){
                nums.push_back(t->data);
                t = t->next;
            }
        }
        sort(nums.begin(), nums.end());
        
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        
        for(int x: nums){
            temp-> next = new Node(x);
            temp = temp->next;
        }
        
        return dummy->next;
    }
};


// approach 2 : using min heap also easy to understand

class Solution {
  public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        // Push the head of each list into heap
        for(Node* head : arr) {
            if(head) pq.push(head);
        }
        
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while(!pq.empty()) {
            Node* smallest = pq.top();
            pq.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if(smallest->next) pq.push(smallest->next);
        }
        
        return dummy->next;
    }
};

