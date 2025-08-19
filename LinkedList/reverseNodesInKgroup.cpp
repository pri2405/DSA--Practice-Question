// Leetcode q no. -  25 (Reverse Nodes in K Group)

// 1st Approach
class Solution {
public:
    int length(ListNode* head){
        int l = 0;
        while(head!=NULL){
            head = head->next;
            l++;
        }
        return l;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {   // T.C. - O(n)  &  S.C. - O(1)
        int n = length(head);
        if(head==NULL || n<k)  return head;
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* curr = temp;
        ListNode* prev = temp;
        ListNode* nxt = temp;
        while(n>=k){
            curr = prev->next;
            nxt = curr->next;
            for(int i=1; i<k; i++){
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            n = n-k;
        }
        return temp->next;
    }
};