// Leetcode q no. - 141    (Linked List Cycle)


// 1st Approach - Floyd's Cycle Detection method
class Solution {
public:
    bool hasCycle(ListNode *head) {           // T.C. - O(n) & S.C. - O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)  return true;
        }
        return false;

    }
};

// 2nd Approach - using Hashing (unordered_map)
class Solution {
public:
    bool hasCycle(ListNode *head) {           // T.C. - O(n) & S.C. - O(n)
        if(head == NULL) return false;

        unordered_map<ListNode*, bool> vis;
        ListNode* curr = head;

        while(curr != NULL) {
            if(vis[curr] == true) return true;

            vis[curr] = true;
            curr = curr->next;
        }
        return false;
    }
};

// 3rd Approach - using Hashing (unordered_set)
class Solution {
public:
    bool hasCycle(ListNode *head) {             // T.C. - O(n) & S.C. - O(n)
        if(head == NULL) return false;

        unordered_set<ListNode*> vis;
        ListNode* curr = head;

        while(curr != NULL) {
            if(vis.find(curr) != vis.end()) return true;

            vis.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};