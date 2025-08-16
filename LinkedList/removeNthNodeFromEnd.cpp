// Leetcode q no. - 19  (Remove nth node from end of list)

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// 1st Approach - two pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            temp = temp->next;
            cnt++;
        }

        int targetIdx = cnt - n;
        if(targetIdx == 0) return head->next;

        ListNode* curr = head;
        for(int i=0; i< targetIdx-1; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};

// 2nd Approach  -  one pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        //traverse fast to (n+1) steps
        for(int i=1; i<=n+1; i++){
            if(fast==NULL) return head->next;
            fast = fast->next;
        }
        //move slow and fast at same pace 
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};