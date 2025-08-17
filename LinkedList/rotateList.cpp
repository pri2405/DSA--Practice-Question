// Leetcode q no. - 61  (Rotate list)

// Given the head of a linked list, rotate the list to the right by k places.

// 1st Approach
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {      // T.C. - O(n) & S.C. - O(1)
        if(head==NULL || k==0) return head;
        int n = 0;   //length of list
        ListNode* temp = head;
        ListNode* tail = NULL;
        while(temp!=NULL){
            if(temp->next==NULL) tail = temp;
            temp = temp->next;
            n++;
        }
        k = k%n;
        if(k==0) return head;
        temp = head;
        for(int i=1; i<n-k; i++){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};