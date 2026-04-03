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
    void reorderList(ListNode* head) {
        // divide in two halfs and merge.
        // reverse second.
        ListNode* slow = head;
        ListNode* fast = head->next;
        // find middle of list
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        } // when fast reaches the end, slow is at middle of list.

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr; // disconnect the slow poiinter (separate lists)
        // reverse second half.
        while (second != nullptr){
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        ListNode* first = head;
        second = prev;
        while (second != nullptr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
