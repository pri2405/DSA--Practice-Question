// Leetcode q no. - 876  (Middle of the Linked List)

// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// 1st Approach - length counting
class Solution {
public:
    ListNode* middleNode(ListNode* head) {        // T.C. - O(n) & S.C. - O(1)
        // Calculate the length of the linked list
        int length = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            curr = curr->next;
            length++;
        }

        // Find the middle node
        int middle = length / 2;
        curr = head;
        for (int i = 0; i < middle; i++) {
            curr = curr->next;
        }

        // Return the middle node
        return curr;
    }
};

//2nd Approach - Two Pointer (slow-fast pointer)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {    // T.C. - O(n) & S.C. - O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};