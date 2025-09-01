#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {2,4,5,6,7,9};
    int K = 11;
    int count = 0;
    
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){
            int sum = 0;  
            for(int k = i; k <= j; k++){  
                sum += v[k];
            }
            if(sum == K){
                cout << "Sum is: " << sum << " (from index " << i << " to " << j << ")" << endl;
                count++;
            }
        }
    }
    cout<<"Count is : "<<count<<endl;
    return 0;
}