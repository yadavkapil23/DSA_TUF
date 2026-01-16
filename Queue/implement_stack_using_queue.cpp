//implement stack using queue.
#include<iostream>
#include<queue>
#include<string>
using namespace std;

queue<int> q1,q2;
    
void pushing(int input){
    while(!q1.empty()){
    q2.push(q1.front());
    q1.pop();
    }

    q1.push(input);
    
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

int pop(){
    int ans = q1.front();
    q1.pop();
    return ans;
}

int topelement(){
    return q1.front();
}
int main(){
    pushing(10);
    pushing(20);
    pushing(30);
    
    cout << "Top: " << topelement() << endl;  
    cout << "Pop: " << pop() << endl;         
    cout << "Top: " << topelement() << endl;  
    
    return 0;
}