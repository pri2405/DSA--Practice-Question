// Leetcode q no. - 83

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// 1st Approach - using recursion
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {     // T.C. - O(n) & S.C. - O(n)
        if(head == NULL || head->next == NULL)  return head;

        head->next = deleteDuplicates(head->next);

        if(head->val == head->next->val) return head->next;
        else return head;
    }
        
};

// 2nd Approach - two pointer
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {     // T.C. - O(n) & S.C. - O(1)
        if(head==NULL || head->next==NULL)  return head;
        ListNode* a = head;
        ListNode* b = head;
        while(b!=NULL){
            while(b!=NULL && a->val==b->val){
            b = b->next;
            }
            a->next = b;
            a = b;
            if(b!=NULL)  b = b->next;
        }
        return head;
    }
        
};