// Leetcode q no. - 21 (Merge Two Sorted List)

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// 1st Approach  -  recursive approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {     // T.C. - O(m+n) & S.C. - O(m+n)
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {      // T.C. - O(m+n) & S.C. - O(1)
        ListNode* ans = new ListNode(100);     
        ListNode* temp = ans;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1==NULL){
            temp->next = list2;
        }
        if(list2==NULL){
            temp->next = list1;
        }
        return ans->next;
    }
};