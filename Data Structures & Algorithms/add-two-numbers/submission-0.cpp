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
        // idea: iterate and getsum of digits, assign to new node. If bigger than 10, then put the remaider and 
        // add 1 to the next sum.

        ListNode* current1 = l1;
        ListNode* current2 = l2;
        ListNode* res = new ListNode();
        ListNode* currentRes = res;

        int addOne = 0;
        while (current1 && current2){
            int sumOfDigits = current1->val + current2->val + addOne;
            if (sumOfDigits >= 10){
                sumOfDigits %= 10;
                addOne = 1;
            } else {
                addOne = 0;
            }
            currentRes->val = sumOfDigits;
            current1 = current1->next;
            current2 = current2->next;
            if (current1 || current2){
                currentRes->next = new ListNode();
                currentRes = currentRes->next;
            }
        }
        // now it's only l1 remaining, we copy it, taking into account the addOne.
        while (current1){
            int digit = current1->val + addOne;
            // it could be a 10!
            if (digit >= 10){
                digit %= 10;
                addOne = 1;
            } else {
                addOne = 0;
            }
            currentRes->val = digit;
            current1 = current1->next;
            if (current1){
                currentRes->next = new ListNode();
                currentRes = currentRes->next;
            }
        }
        while (current2){
            int digit = current2->val + addOne;
            // it could be a 10!
            if (digit >= 10){
                digit %= 10;
                addOne = 1;
            } else {
                addOne = 0;
            }
            currentRes->val = digit;
            current2 = current2->next;
            if (current2){
                currentRes->next = new ListNode();
                currentRes = currentRes->next;
            }
        }

        // addOne carry
        if (addOne){
            currentRes->next = new ListNode(addOne);
            currentRes = currentRes->next;
        }

        return res;
    }
};
