class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        ListNode* temp = head;
        int n = 0;
        while (temp) {
            temp = temp->next;
            n++;
        }

        k = k % n;
        if (k == 0) return head;

        int forward = n - k;

        // Step 2: Reach (forward-1)th node
        temp = head;
        while (forward > 1) {
            temp = temp->next;
            forward--;
        }

        // Step 3: Break and rearrange
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        ListNode* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }

        tail->next = head;

        return newHead;
    }
};