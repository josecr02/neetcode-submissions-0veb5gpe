/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // more optimal solution with just O(1) space.
        // the trick is to put the copied node right after the og node inside the og list.
        if (head == nullptr) return nullptr;

        Node* l1 = head;
        while (l1){
            Node* l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
        }

        Node* newHead = head->next; // first copy
        l1 = head; // first no copy
        while (l1){
            if (l1->random){
                // we set the random field of the copy of this l1 node
                l1->next->random = l1->random->next;
            }
            l1 = l1->next->next;
        }

        l1 = head;
        // now we separate the copies list
        while (l1){
            Node* l2 = l1->next;
            l1->next = l2->next; //remove the interleaved
            if (l2->next){
                l2->next = l2->next->next; // l2->next was next original and now set it to the next copy.
            }
            l1 = l1->next;
        }

        return newHead;
    }
};
