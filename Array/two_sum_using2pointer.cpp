#include<iostream>
#include<vector>
using namespace std;
void my_function(vector<int> &v , int target){
    int sum = 0;
    int left = 0;
    int right = v.size() - 1;
    while(left < right){
        sum = v[left] + v[right];
        if(sum == target){
            cout<<"Found : "<<v[left]<<" and "<<v[right]<<endl;
            left++,right --;
        }
        else if (sum < target){
            left++;
        }
        else{
            right--;
        }
    }
}
int main(){
    vector<int> v{1,2,3,4,5,23,54,76};
    int target = 27;
    my_function(v,target);
    return 0;
}