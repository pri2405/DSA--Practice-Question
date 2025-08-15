// Leetcode q no. - 234 (Palindrome Linked List)

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// 1st Approach - using stack
class Solution {
public:
    
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(!st.empty()) {
            if(st.top() != temp->val) return false;
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};

// 2nd Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head){    
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while(curr){
            Next = Next->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
    return prev;
}
    bool isPalindrome(ListNode* head) {        // T.C. - O(n) & S.C. - O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is a the left middle/middle  
        ListNode* newHead = reverseList(slow->next);         // reverse other half nodes of linked list
        ListNode* a = head;
        ListNode* b = newHead;
        while(b){
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};