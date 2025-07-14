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
    int getDecimalValue(ListNode* head) {
        string binary_number;
        ListNode* temp = head;//1

        while(temp){//1 // 0 // 1 //break
            char value = temp->val + '0';//'1' // '0' // '1'
            binary_number = binary_number + value;//101

            temp = temp->next;//0//1//nullptr
        }

        int n = binary_number.length();//3

        int answer = 0;
        int right_index = 0;
        for(int i = n - 1; i >= 0; i--){ //break 
            if(binary_number[i] == '1'){//true //false // true
                answer += (1 << right_index);//1 + (2^2 = 4) = 5
            }
            right_index += 1;//1 // 2 // 3
        }

        return answer;
    }
};