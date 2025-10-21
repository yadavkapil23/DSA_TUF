#include<iostream>
using namespace std;
int Sum(int n){
    if(n <= 0)  
        return 0;
    return n + Sum(n-1);  
}

int main(){
    int n;
    cout << "Enter n : ";
    cin >> n;

    if(n < 0)
        cout << "Cannot add negative numbers." << endl;
    else
        cout << "Sum = " << Sum(n) << endl;
}
