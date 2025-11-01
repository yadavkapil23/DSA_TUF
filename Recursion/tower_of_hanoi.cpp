//from - source rod.
//aux - temporary helper.
//to - destination rod.

#include<iostream>
using namespace std;
void towerofhanoi(int n,char from,char to, char aux){
    if(n==0){
        return; //base case;
    }

    towerofhanoi(n-1,from,aux,to);
    cout<<"Moving"<<n<<"th disk from : "<<from<<" to : "<<to<<endl;
    towerofhanoi(n-1,aux,to,from);
}
int main(){
int n =3;
towerofhanoi(3,'A','C','B');
}
