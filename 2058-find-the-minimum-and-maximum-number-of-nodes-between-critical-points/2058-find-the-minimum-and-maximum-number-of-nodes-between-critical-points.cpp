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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticals;

        ListNode* temp = head;
        int c = 1;
        int last = temp->val;
        temp = temp->next;
        while(temp && temp->next){
            int next = temp->next->val;

            int curr = temp->val;
            if((curr > last && curr > next) || (curr < last && curr < next)){
                criticals.push_back(c);
            }

            c++;
            last = curr;
            temp = temp->next;
        }

        int n = criticals.size();
        if(n < 2)   return {-1, -1};
        int maxi = criticals[n - 1] - criticals[0];
        int mini = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            mini = min(mini, criticals[i + 1] - criticals[i]);
        }

        return {mini, maxi};
    }
};