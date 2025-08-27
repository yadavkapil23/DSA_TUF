#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v{0,1,2,2,2,1,0,0,1,0,2,0,1};
    int count0 = 0; //used to store the count of zero.
    int count1 = 0; //used to store the count of one.
    int count2 = 0; //used to store the count of two.
    
    vector<int> temp0;
    vector<int> temp1;
    vector<int> temp2;

    int n = v.size();
    for(int i=0 ; i<n ; i++){
        if(v[i] == 0){
            temp0.push_back(v[i]);
            count0++;
        }
        else if(v[i] == 1){
            temp1.push_back(v[i]);
            count1++;
        }
        else if(v[i]==2){
            temp2.push_back(v[i]);
            count2++;
        }
    }

    int size0 = temp0.size();
    int size1 = temp1.size();
    int size2 = temp2.size();

    vector<int> answer;

    for(int i=0 ; i<size0 ; i++){
        answer.push_back(temp0[i]);
    }

    for(int i=0 ; i<size1 ; i++){
        answer.push_back(temp1[i]);
    }
    for(int i=0 ; i<size2 ; i++){
        answer.push_back(temp2[i]);
    }


    int size_ans = answer.size();
    for(int x=0 ; x<size_ans ; x++){
        cout<<answer[x]<<" ";
    }
}