#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

float squareroot(float low,float high,float n){
    if(n==0 || n==1){
        return n;
    }
    else{
        while(low <= high){
        int mid = low + (high-low)/2;

        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid < n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
}
}

int main(){
    float n;
    cout<<"Enter a number to find out squre root : ";cin>>n;

    float low = 0;
    float high = n;
    float ans = squareroot(low,high,n);
    cout<<ans<<endl;
}