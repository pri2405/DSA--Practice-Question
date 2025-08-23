// Leetcode q no. - 225   (Implement Stack Using Queues)

// 1st Approach   -  using two queue
class MyStack {
    queue<int> q1;
    queue<int> q2;
    int topEle;
public:
    MyStack() {
        
    }
    
    void push(int x) {        // T.C. - O(1)  &  S.C. - O(1)
        topEle = x;
        q1.push(x);
    }
    
    int pop() {                 // T.C. - O(n) & S.C. - O(n)
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        
        while(!q2.empty()) {
            if(q2.size() == 1) topEle = q2.front();
            q1.push(q2.front());
            q2.pop();
            
        }
        return x;
    }
    
    int top() {                  // T.C. - O(1)  &  S.C. - O(1)
        return topEle;
    }
    
    bool empty() {                 // T.C. - O(1)  &  S.C. - O(1)
        return q1.empty();
    }
};

// 2nd Approach - using one queue 
class MyStack {
    queue<int> q1;
    int topEle;
public:
    MyStack() {
        
    }
    
    void push(int x) {               // T.C. - O(1)  &  S.C. - O(1)
        topEle = x;
        q1.push(x);
    }
    
    int pop() {                     // T.C. - O(n)  &  S.C. - O(n)
        int ele;
        int cnt = 0;
        while(cnt != q1.size()-1) {
            ele = q1.front();
            q1.push(ele);
            q1.pop();
            cnt++;
        }
        topEle = ele;
        int x = q1.front();
        q1.pop();
        
        return x;
    }
    
    int top() {                        // T.C. - O(1)  &  S.C. - O(1)
        return topEle;
    }
    
    bool empty() {                     // T.C. - O(1)  &  S.C. - O(1)
        return q1.empty();
    }
};