#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
queue<int> q;
q.push(45);
q.push(12);
q.push(98);
cout<<"The top element of the Queue is : "<<q.front()<<endl;
cout<<"The last element of the Queue is : "<<q.back()<<endl;
cout<<"Size is : "<<q.size()<<endl;
while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
}
if(q.empty()){
    cout<<"Queue is Empty"<<endl;
}
else{
    cout<<"Queue is not empty"<<endl;
}
return 0;
}