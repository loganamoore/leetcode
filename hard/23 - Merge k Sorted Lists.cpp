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
    // Swap the values of two nodes.
    void swap(ListNode* n1, ListNode* n2){
        int t = n1->val;
        n1->val = n2->val;
        n2->val = t;
    }

    // Return the node at a position in the list or nullptr
    ListNode* nodeAtPos(ListNode* list, unsigned int pos){
        ListNode* n = list;
        for(int i = 0; i < pos && n; i++)
            n = n->next;
        return n;
    }

    // Partition the list
    int part(ListNode* list, int min, int max){
        ListNode* pivot = nodeAtPos(list, max);
        int i = min - 1;

        ListNode* minNode = nodeAtPos(list, min);
        ListNode* maxNode = nodeAtPos(list, max);
        ListNode* n = minNode;

        while(n && n != maxNode){
            if(n->val <= pivot->val){
                i++;
                swap(nodeAtPos(list, i), n);
            }
            n = n->next;
        }

        swap(nodeAtPos(list, i + 1), maxNode);
        return i + 1;
    }

    // Quicksort
    void quick_sort(ListNode* list, int min, int max){
        if(min < max){
            int pi = part(list, min, max);

            quick_sort(list, min, pi - 1);
            quick_sort(list, pi + 1, max);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int listsSize = lists.size();
        if(!listsSize)
            return nullptr;

        ListNode dummy;
        int size = 0;

        // Merge all the lists together.
        for(int i = 0; i < listsSize - 1; i++){
            ListNode* n = lists.at(i);

            // If the list is empty, ignore it
            if(!n)
                continue;

            // Set the dummy to the first found non-null ListNode*
            if(!dummy.next)
                dummy.next = n;

            // Go to the last node and count the nodes
            while(n->next){
                n = n->next;
                size++;
            }

            // Attach the root of the next list to the end of this list.
            n->next = lists.at(i + 1);
            size++;
        }

        // Sort if it even needs to be sorted.
        if(size > 1)
            quick_sort(dummy.next, 0, size);

        return dummy.next;

    }
};
