#include<iostream>
using namespace std;
void Blast(int count){
    if(count == 5){
        cout<<"BOOOOMMM";
        return;
    }
    
    cout<<"No is : "<<count<<endl;
    count++;
    Blast(count);
}
int main(){
    int count = 1;
    Blast(count);
}