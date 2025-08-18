// Leetcode q no. - 430  (Flatten a multilevel Doubly Linked List)

// 1st Approach  -  using recursion
class Solution {
public:
    Node* flatten(Node* head) {            // T.C. - O(n) & S.C. - O(1)
        Node* temp = head;
        while(temp){
            Node* a = temp->next;
            if(temp->child!=NULL){
                Node* a = temp->next;
                Node* c = temp->child;
                temp->child = NULL;  
                c = flatten(c);   //recursion
                temp->next = c;
                c->prev = temp;
                while(c->next!=NULL){
                    c = c->next;
                }
                c->next = a;
                if(a)  a->prev = c;
            }
            temp = a;
        }
        return head;
    }
};