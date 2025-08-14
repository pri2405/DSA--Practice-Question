// Leetcode q no. - 206   (Reverse Linked List)

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// 1st Approach - using recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {         // T.C. - O(n) & S.C. - O(n)
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

// 2nd Approach - Iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {            // T.C. - O(n) & S.C. - O(1)
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};