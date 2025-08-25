#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n1;
    cout<<"Enter the size of first array : ";cin>>n1;
    vector<int> v(n1);
    for(int i=0; i<n1; i++){
        cin>>v[i];
    }

    int n2;
    cout<<"enter the size of 2nd array : ";cin>>n2;
    vector<int> v2(n2);
    for(int i=0; i<n2; i++){  
        cin>>v2[i];
    }

    // LOGIC
    vector<int> ans;
    vector<int> visited(n2, 0);  

    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(v[i] == v2[j] && visited[j] == 0){
                ans.push_back(v[i]);
                visited[j] = 1;
                break;
            }
            if(v2[j] > v[i]){  
                break;
            }
        }
    }
    
    for(auto i : ans){  
        cout<<i<<" ";
    }

    return 0;
}