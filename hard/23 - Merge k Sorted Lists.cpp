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

    // Borrowed from easy/#21 - Merge Two Sorted Lists.cpp
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(!lists.size())
            return nullptr;

        while(lists.size() > 1){
            vector<ListNode*> merged;

            for(int i = 0; i < lists.size(); i += 2){
                ListNode* n1 = lists[i];
                ListNode* n2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                merged.push_back(mergeTwoLists(n1, n2));
            }

            lists = merged;
        }

        return lists[0];

    }

};
