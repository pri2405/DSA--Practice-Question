// Leetcode q no. - 24  (Swap nodes in pairs)

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

// 1st Approach  -  Iterative Approach
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {             // T.C. - O(n)  &  S.C. - O(1)
        if(head==NULL || head->next==NULL) return head; 
        ListNode* prev = head;
        ListNode* curr = head->next->next;
        head = head->next;
        head->next = prev;
        while(curr!=NULL && curr->next!=NULL){
            prev->next = curr->next;
            prev = curr;
            ListNode* temp = curr->next->next;
            curr->next->next = curr;
            curr = temp;
        }
        prev->next = curr;
        return head;
    }
};

// 2nd Approach  -  recursive approach
class Solution {
public:
    ListNode* helper(ListNode* curr) {                  // T.C. - O(n) & S.C. - O(n)
        if(curr == NULL || curr->next == NULL) return curr;

        ListNode* nxt = curr->next->next;
        ListNode* head = curr->next;
        head->next = curr;
        curr->next = helper(nxt);
        return  head;
    }
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
        
    }
};