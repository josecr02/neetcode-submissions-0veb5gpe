// Singly Linked List Node
class ListNode {
    public:
        int val;
        ListNode* next;
    
        // Constructor that sets 'next' to nullptr by default
        ListNode(int val) : val(val), next(nullptr) {}
    
        // Constructor that accepts both value and next node
        ListNode(int val, ListNode* next) : val(val), next(next) {}
};
  
// Implementation for Singly Linked List
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    // Constructor
    LinkedList() {
        // Init the list with a 'dummy' node which makes
        // removing a node from the beginning of list easier.
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (curr != nullptr) {
            if (i == index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1;  // Index out of bounds or list is empty
    }

    // Method to insert at the head
    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        if (newNode->next == nullptr) {  // If list was empty before insertion
            tail = newNode;
        }
    }
    
    // Method to insert at the tail
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    // Method to remove at given index
    bool remove(int index) {
        int i = 0;
        ListNode* curr = head;
        while (i < index && curr != nullptr) {
            i++;
            curr = curr->next;
        }

        // Remove the node ahead of curr
        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) {
                tail = curr;
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    // Method to get values of the linked list
    vector<int> getValues() {
        vector<int> res;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        return res;
    }
};