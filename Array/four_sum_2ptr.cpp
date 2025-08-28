#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void my_function(vector<int> &v, int target){
    sort(v.begin(),v.end());
    int sum = 0;
        bool found = false;
    for(int i=0 ; i<v.size()-3 ; i++){
        for(int j=i+1 ; j<v.size()-2 ; j++){
            int left = j+1;
            int right = v.size()-1;
            while(left<right){
                int sum = v[i] + v[j] + v[left] + v[right];
                if(target == sum){
                    cout<<"Numbers are : "<<v[i]<<" and "<<v[j]<<" and "<<v[left]<<" or "<<v[right];
                    found = true;
                    left++;
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
            }
        }
    }
    if(!found){
       cout<<"not found";
    }
}

int main(){
    int n;
    cout<<"enter the n : ";cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cout<<"enter the "<<i+1<<" element : ";cin>>v[i];
    }
    int target = 50;
    my_function(v,target);
    return 0;
}