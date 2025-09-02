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
    Node* swapKth(Node* head, int k) {
        // code here
        Node* temp = head;
        int n = 0;
        
        while(temp){
            temp = temp->next;
            n++;
        }
        
        int kth_start = -1;
        int kth_end = -1;
        // kth node from end = n - k + 1th node from start
        
        int pos = 0;
        temp = head;
        while(temp){
            pos++;
            if(pos == k){
                kth_start = temp->data;
            }            
            if(pos == n - k + 1){
                kth_end = temp->data;
            }
            temp = temp->next;
        }
        
        
        pos = 0;
        temp = head;
        
        while(temp){
            pos++;
            if(pos == k){
                temp->data = kth_end;
            }
            if(pos == n - k + 1){
                temp->data = kth_start;
            }
            temp = temp->next;
        }
        
        return head;
    }
};