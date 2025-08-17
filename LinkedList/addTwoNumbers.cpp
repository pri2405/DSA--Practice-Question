// Leetcode q no. - 2  (Add Two Numbers)

// 1st Approach
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){    // T.C. - O(n) & S.C. - O(1)
        ListNode* t = new ListNode(-1);
        ListNode* temp = t;
        int c = 0;
        while(l1!=NULL || l2!=NULL || c){
            int sum = 0;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += c;
            c = sum/10;
            ListNode* n = new ListNode(sum%10);
            temp->next = n;
            temp = temp->next;
        }
        return t->next;
    }
};