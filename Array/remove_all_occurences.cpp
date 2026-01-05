#include<iostream>
#include<vector>
using namespace std;

// ham val k equal elements ko remove krne k bjay, 
// val k equal nhi h unko alag kr lete h aur unka size return kr dete h
int removeElement(vector<int>& v, int val) {
    int n = v.size();
    int k = 0;

    for(int i=0 ; i<n ; i++){
        if(v[i] != val){
            v[k] = v[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    
    cout << "Original array: ";
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    int k = removeElement(nums, val);
    
    cout << "After removing " << val << ": ";
    for(int i=0; i<k; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    
    cout << "Number of remaining elements (k): " << k << endl;
    
    return 0;
}
