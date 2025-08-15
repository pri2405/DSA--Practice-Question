// Leetcode q no. - 160

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// 1st Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {     // T.C. - O(m+n) & S.C. - O(1)
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0;
        while(tempA!=NULL){
            lenA++;
            tempA = tempA->next;
        }
        int lenB = 0;
        while(tempB!=NULL){
            lenB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if(lenA>lenB){
            int diff = lenA - lenB;
            for(int i=1; i<=diff; i++){
                tempA = tempA->next;
            }
            while(tempA!=tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempA;
        }
        else{
            int diff = lenB - lenA;
            for(int i=1; i<=diff; i++){
                tempB = tempB->next;
            }
            while(tempA!=tempB){
                tempA = tempA->next;
                tempB = tempB->next;
            }
            return tempB;
        }
    }
};

// 2nd Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {          // T.C. - O(m+n) & S.C. - O(1)
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;

            if(tempA == tempB) return tempA;
            
            if(tempA == NULL) tempA = headB;
            if(tempB == NULL) tempB = headA;
        }
        return tempA;
    }
};