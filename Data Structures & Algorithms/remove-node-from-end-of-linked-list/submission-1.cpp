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
        // we iterate through the list, mainting a stack and then remove the nth element.
        
        stack<ListNode*> order;
        ListNode* cur = head;
        while (cur){
            order.push(cur);
            cur = cur->next;
        }
        // cur is nullptr
        while (n > 0){
            cur = order.top();
            order.pop();
            --n;
        }
        // last popped is elemnt to remove
        // cur needs to be removed, we readust previous->next pointer.

        if (!order.empty()){
            // there is a node to readjust
            ListNode* prev = order.top();
            order.pop();
            prev->next = cur->next;
            cur->next = nullptr;
            delete cur;
            // now we pop the stack and return the head
            while (!order.empty()){
                prev = order.top();
                order.pop();
            }
            return prev;
        } else {
            // we remove the first element of the list, so the next element is the new head
            ListNode* newHead = cur->next;
            cur->next = nullptr;
            delete cur;
            return newHead;
        }
    }
};
