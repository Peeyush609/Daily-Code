/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public: 
    int lengthOfLoop(Node* head) {
      
        unordered_set<Node*> visited;
        Node* current = head;
        int count = 0;
    
        while (current != nullptr) {
          
            // if the node is already visited, 
          	// it means there is a loop
            if (visited.find(current) != visited.end()) {
                Node* startOfLoop = current;
                do {
                    count++;
                    current = current->next;
                } while (current != startOfLoop);
                return count;
            }
    
            // mark the current node as visited
            visited.insert(current);
    
            // move to the next node
            current = current->next;
        }
    
        return 0;
    }
};