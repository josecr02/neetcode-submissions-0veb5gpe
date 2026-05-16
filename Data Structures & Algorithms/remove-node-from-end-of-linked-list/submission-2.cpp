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
        // optimal solution, two pointer techniques O(1) space.
        ListNode dummy = ListNode(0, head);
        ListNode* left = &dummy;
        ListNode* right = head;

        while (n > 0){
            right = right->next;
            --n;
        }

        while (right != nullptr){
            right = right->next;
            left = left->next;
        }

        // now the left pointer + 1 is nth starting from the end
        // we delete the left pointer
        left->next = left->next->next;
        return dummy.next;
    }
};
