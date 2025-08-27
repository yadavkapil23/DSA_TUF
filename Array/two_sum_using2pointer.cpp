//FOR THIS THE ARRAY MUST BE SORTED 


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void my_function(vector<int> &v , int target){
    sort(v.begin(),v.end());
    int sum = 0;
    int left = 0; //points to starting.
    int right = v.size() - 1;  //points to the end of array.

    while(left < right){  //As long as the two pointers don’t cross each other, keep checking the sum of the current two numbers.
        sum = v[left] + v[right];

        if(sum == target){
            cout<<"Found : "<<v[left]<<" and "<<v[right]<<endl;
            left++,right --; //move both pointers inward to keep searching.
        }
        else if (sum < target){
            left++; //if sum is too small move the pointer to the right 
        }
        else{
            right--; //if sum is too large  , move the pointer to the left.
        }
    }
}
int main(){
    int n;
    cout<<"enter n : ";cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cout<<"Enter the "<<i<<" element : ";cin>>v[i];
    }
    int target = 27;
    my_function(v,target);
    return 0;
}