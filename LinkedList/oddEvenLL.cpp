// Leetcode q no. - 328 (Odd Even Linked List)

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// 1st Approach  - Two pointer
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {     // T.C. - O(n) & S.C. - O(1)
        if(head==NULL || head->next==NULL)  return head;
        ListNode* odd = head;
        ListNode* evn = head->next;
        ListNode* t = evn;
        while(evn!=NULL && evn->next!=NULL){
            odd->next = evn->next;
            odd = odd->next;
            evn->next = odd->next;
            evn = evn->next;
        }
        odd->next = t;
        return head;
    }
};