// Leetcode q no. - 203 (Remove linked list elements)

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// 1st Approach
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val==val){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return newHead->next;
    }
};

// 2nd Approach
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;

        while(head!=NULL && head->val==val){
            head = head->next;
        }
        ListNode* curr = head;
        while(curr!=NULL  && curr->next!=NULL){
            if(curr->next->val==val){
                curr->next = curr->next->next;
            }
            else
                curr = curr->next;
        }
        return head;
    }
};