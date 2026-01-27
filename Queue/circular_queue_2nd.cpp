class MyCircularQueue {
private:
vector<int> q;
int rear;
int front;
int size;
int capacity;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        rear = -1;
        front = 0;
        size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
       if(isFull()){
        return false;
       } 
       else{
        rear = (rear+1)%capacity;
        q[rear] = value;
        size++;
        return true;
       }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else{
            front = (front+1)%capacity;
            size--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size==capacity){
            return true;
        }
        return false;
    }
};

