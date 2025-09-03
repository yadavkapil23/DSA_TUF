#include<iostream>
#include<vector>
using namespace std;
vector<int> Moore(vector<int>&v , int n){
    int candidate = 0;
    int candidate2 = 0;
    int count = 0;
    int count2 = 0;
    for(int i=0 ; i<n ; i++){
        if(count == 0){
            candidate = v[i];
            count = 1;
        }
        else if(count2 == 0){
            candidate2 = v[i];
            count2 = 1;
        }
        else if(v[i] == candidate){
            count++;
        }
        else if(v[i] == candidate2){
            count2++;
        }
        else{
            count--;
            count2--;
        }

    }

    int count = 0;
    int count2 = 0;
    for(int i=0 ; i<n ; i++){
        if(v[i] == candidate){
            count++;
        }
        else if(v[i] == candidate2){
            count2++;
        }
    }


    vector<int> result;

    if(count > n/3){
        result.push_back(candidate);
    }
    else if(count2 > n/3){
        result.push_back(candidate2);
    }

    return result;

}
int main(){
    int n;
    cout<<"enter n :";cin>>n;
    vector<int> v(n);

    
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
    }

    Moore(v,n);

}