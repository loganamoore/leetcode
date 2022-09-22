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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode dummy;
        ListNode* n = &dummy;

        unsigned int carry = 0;

        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = floor(sum / 10);

            ListNode* t = new ListNode;
            t->val = sum - (carry * 10);
            n->next = t;
            n = n->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = l1->val + carry;
            carry = floor(sum / 10);
            l1->val = sum - (carry * 10);

            n->next = l1;
            n = n->next;
            l1 = l1->next;
        }

        while(l2){
            int sum = l2->val + carry;
            carry = floor(sum / 10);
            l2->val = sum - (carry * 10);

            n->next = l2;
            n = n->next;
            l2 = l2->next;
        }

        if(carry){
            ListNode* t = new ListNode;
            t->val = carry;
            n->next = t;
        }

        return dummy.next;

    }
};
