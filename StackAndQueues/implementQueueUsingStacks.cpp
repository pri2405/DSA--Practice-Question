// Leetcode q no. - 232   (Implement Queue using stacks)



// 1st Approach
class MyQueue {                 
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {               // T.C. - O(n)  &  S.C. - O(n)
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {                     // T.C. - O(1)  &  S.C. - O(1)
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {                     // T.C. - O(1)  &  S.C. - O(1)
        return st1.top();
    }
                                      // T.C. - O(1)  &  S.C. - O(1)
    bool empty() {
        return st1.empty();
    }
};


// 2nd Approach
class MyQueue {
    stack<int> st1;
    stack<int> st2;
    int front;
public:
    MyQueue() {
        
    }
    
    void push(int x) {            // T.C. - O(1) & S.C. - O(1)
        if (st1.empty())
            front = x;
        st1.push(x);
    }
    
    int pop() {                  // amortised T.C. - O(1) & worst T.C. - O(n)  &  S.C. - O(n)
        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int x = st2.top();
        st2.pop();
        return x;
    }
    
    int peek() {                  // T.C. - O(1) & S.C. - O(1)
        if (!st2.empty()) 
            return st2.top();

        return front;
    }
    
    bool empty() {                     // T.C. - O(1) & S.C. - O(1)
        return st1.empty() && st2.empty();
    }
};