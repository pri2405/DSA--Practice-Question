// Leetcode q no. - 155 (Min Stack)

// 1st Approach - using two stack
class MinStack {            // T.C. - O(1) for all operations & S.C.- O(n) worst case
    stack<int> st, s;
public:
    
    MinStack(){ 

    }
    void push(int val){  
       s.push(val);
       if(st.empty() || val <= st.top()) st.push(val);
    }
    void pop(){ 
        if(s.top() == st.top()) st.pop();
        s.pop();
    }
    int top(){ 
        if(s.empty()) return -1;
        return s.top();
    }
    int getMin(){  
        if(st.empty()) return -1;
        return st.top();
    }
};

// 2nd Approach - Using one Stack
class MinStack {
    long long mn;
    stack<long long> st;
public:
    
    MinStack(){  
        mn = LLONG_MAX;
    }
    void push(int val){ 
        long long x = (long long)val;
        if(st.size()==0){
            st.push(x);
            mn = x;
        }
        else if(val>=mn)  st.push(val);
        else{      // val < mn
            long long x = (long long)2*val-mn;
            st.push(x);
            mn = val;
        }
    }
    void pop(){ 
        if(st.top()<mn){    //st.top()<mn : A fake value is present
            long long oldMin = 2*mn - st.top();
            mn = oldMin;
        }
        st.pop();
    }
    int top(){  
        if(st.top()<mn) return (int)mn;
        else return (int)st.top();
    }
    int getMin(){
        return (int)mn;
    }
};