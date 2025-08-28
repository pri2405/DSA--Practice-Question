// Leetcode q no. - 622  (Design Circular queue)

// 1st Approach
class MyCircularQueue {            // T.C.- O(1)  &  S.C.- O(k)
    vector<int> v;
    int front, rear, size, count;
public:
    MyCircularQueue(int k) {
        v.resize(k);
        front = 0;
        rear = -1;
        count = 0;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % size;
        v[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % size;
        count--;
        return true;  
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};