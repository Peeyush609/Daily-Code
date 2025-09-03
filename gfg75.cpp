/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr){
            prev=curr->prev;
            
            curr->prev=curr->next;
            curr->next=prev;
            
            curr=curr->prev;
        }
        
        return prev->prev;
    }
};