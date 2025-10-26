#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void threeSum(vector<int>& v, int target) {
    // MUST sort the array first
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size() - 2; i++) { 
        if(i > 0 && v[i] == v[i-1]){ 
        continue; 
        }
        //here v.size() - 2 , because after that there will be two elements left , which can form triplet.
        int left = i + 1;
        int right = v.size() - 1;
        
        while(left < right) {
            int sum = v[i] + v[left] + v[right];
            
            if(sum == target) {
                cout << "Found: " << v[i] << ", " << v[left] << ", " << v[right] << endl;

                while(left<right && v[left] == v[left+1]){
                    left++;
                }
                while(left<right && v[right] == v[right-1]){
                    right--;
                }
                left++;
                right--;
            }

            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
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
    int target = 200;
    threeSum(v,target);
    return 0;
}