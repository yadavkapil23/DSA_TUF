//implementing the stack using the queues.
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

void sq(queue<int> &q1,queue<int> &q2,int x){
    
    q2.push(x);

    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    
    //instead of swapping we can also push the elements of q2 to q1.
    
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    
}

int main(){
    queue<int> q1;
    queue<int> q2;
    
    for(int i=39 ; i<46 ; i++){
        sq(q1,q2,i);
    }
    
        //printing the result.
    while(!q1.empty()){
        cout<<q1.front()<<endl;
        q1.pop();
    }
    
    return 0;
}