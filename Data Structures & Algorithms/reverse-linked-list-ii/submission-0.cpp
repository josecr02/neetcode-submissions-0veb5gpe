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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* leftPrev = &dummy;
        ListNode* cur = head;

        for (int i = 0; i < left - 1; ++i){
            leftPrev = cur;
            cur = cur->next;
        }

        // now we reverse the inner
        ListNode* prev = nullptr;
        for (int i = 0; i < right - left + 1; ++i){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        // now we reversed the list, but have to adjust the endings
        // leftPrev->next is now the ending the of inner reversed list, it becomes the new head.
        // so we set its next value to the node that came right after the list
        leftPrev->next->next = cur;
        leftPrev->next = prev;

        return dummy.next;
    }
};