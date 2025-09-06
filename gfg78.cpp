//to find the length of the loop in ll


/*
general solution common simple sa

check below for optimal sol using fast and slow pointer
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


//this is using floyd's cycle algo kuch nhi ye bhi easy hi hai dekho acche se bs


class Solution {
public: 
    // Returns count of nodes present in loop.
    int countNodes(Node* node) {
        int res = 1;
        Node* curr = node;
        while (curr->next != node) {
            res++;
            curr = curr->next;
        }
        return res;
    }
    
    // Detects and Counts nodes in loop
    int lengthOfLoop(Node* head) {
        Node *slow = head, *fast = head;
    
        while (slow != nullptr && fast != nullptr 
               && fast->next != nullptr) {
                   
            slow = slow->next;
            fast = fast->next->next;
    
            // If slow and fast meet at
            // some point then there is a loop
            if (slow == fast)
                return countNodes(slow);
        }
    
        return 0;
    }
};