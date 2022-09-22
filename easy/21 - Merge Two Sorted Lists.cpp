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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy;

        ListNode* t = &dummy,
                * n1 = list1,
                * n2 = list2;

        while(n1 && n2){

            if(n1->val <= n2->val){
                t->next = n1;
                n1 = n1->next;
            }
            else{
                t->next = n2;
                n2 = n2->next;
            }

            t = t->next;
        }

        if(n1)
            t->next = n1;
        else if(n2)
            t->next = n2;

        return dummy.next;

    }
};
