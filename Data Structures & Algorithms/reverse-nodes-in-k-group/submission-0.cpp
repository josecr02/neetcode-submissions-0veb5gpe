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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true){
            ListNode* kth = getKth(groupPrev, k);
            if (!kth){
                break;
            }
            ListNode* groupNext = kth->next; // both are first node after the current group to reverse
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next; // first node to reverse
            while (curr != groupNext){
                // reverse until we stop at 1 beyond kth node
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr; // and now update backwards (new end)
                curr = tmp; // now continue on the next original node to reverse
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }

        return dummy->next;
    }

private:
    ListNode* getKth(ListNode* curr, int k){ // get the curr + k node
        while (curr && k > 0){
            curr = curr->next;
            --k;
        }
        return curr;
    }
};
