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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy;
        dummy.next = head;

        ListNode * i = head,
                 * nthNode = head,
                 * nthPrev = &dummy;

        int ic = 0;

        while(i){
            if(ic > n - 1){
                nthNode = nthNode->next;
                nthPrev = nthPrev->next;
            }

            i = i->next;
            ic++;
        }

        nthPrev->next = nthNode->next;

        return dummy.next;

    }
};
