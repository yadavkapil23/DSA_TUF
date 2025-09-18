//IN THIS THE ELEMENTS CAN BE THE SAME.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int rotate_sort(vector<int>&v,int n,int k,int target){
    if (n == 0){
        return -1;
    }

    sort(v.begin(),v.end());
    k = k%n;

    //now rotating the array by k.
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());

    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = left + (right-left)/2;

        if(v[mid] == target){
            return mid;
        }

        if(v[left] == v[mid] && v[mid] == v[right]){
            left++;
            right--;
            continue;
        }

        //GOING TO THE LEFT HALF.
        else if(v[left] <= v[mid]){
            if(target >= v[left] && target < v[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        //GOING TO THE RIGHT HALF.
        else if(v[right] > v[mid]){
            if(target <= v[right] && target > v[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }

    }
    return -1;
}
int main(){
int n;
cin>>n;
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
int k;
cout<<"enter k (no of elements to rotate) : ";cin>>k;
int target;
cin>>target;

int x = rotate_sort(v,n,k,target);
cout<<x<<endl;
return 0;
}