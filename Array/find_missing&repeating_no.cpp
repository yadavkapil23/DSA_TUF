//code to find the missing and the repeating number.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int repeating(vector<int>&v,int n,int &count){
    sort(v.begin(),v.end());
    int repeat_element;
    for(int i=1 ; i<n ; i++){
        if(v[i] == v[i-1]){
            count++;
            repeat_element = v[i];
        }
        else{
            continue;
        }
    }
    return repeat_element;
}

int missing(vector<int>&v,int n){
    int sum = 0; 
    for(int i=0 ; i<n; i++){
        sum += v[i];
    }
    int org_sum = n * (n+1) / 2;
    
    int result = org_sum - sum;
    return result;
}
int main(){
    vector<int> v = {1, 2, 2, 4, 5, 6};
    int n = v.size();
    int count = 0;
    
    int x = repeating(v,n,count);
    int y = missing(v,n);
    
    cout << "Missing element is: " << y<< ", Repeating element is: " << x<< ", No. of times repeated: " << count << endl;

    return 0;
}
