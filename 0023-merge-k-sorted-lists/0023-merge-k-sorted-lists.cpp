/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())    return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> minheap;

        for(auto &list: lists){
            if(list)    minheap.push(list);
        }

        ListNode* dummyhead = new ListNode(-1);
        ListNode* dummy = dummyhead;
        while(!minheap.empty()){
            auto curr = minheap.top();
            minheap.pop();

            if(curr->next){
                minheap.push(curr->next);
            }

            curr->next = nullptr;
            dummy->next = curr;
            dummy = dummy->next;
        }
        return dummyhead->next;
    }
};