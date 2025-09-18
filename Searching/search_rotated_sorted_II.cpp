#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rotate_sort(vector<int>&v, int n, int k, int target){
    if (n == 0){
        return -1;
    }
    
    sort(v.begin(), v.end());
    k = k % n;
    
    // Rotating the array by k
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
    
    int left = 0;
    int right = n - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if(v[mid] == target){
            return mid;
        }
        
        // Handle duplicates - can't determine which side is sorted
        if(v[left] == v[mid] && v[mid] == v[right]){
            left++;
            right--;
            continue;
        }
        
        // Left half is sorted
        if(v[left] <= v[mid]){
            if(target >= v[left] && target < v[mid]){
                right = mid - 1;  // Target in left half
            }
            else{
                left = mid + 1;   // Target in right half
            }
        }
        // Right half is sorted (when left half is not sorted)
        else {
            if(target > v[mid] && target <= v[right]){
                left = mid + 1;   // Target in right half
            }
            else{
                right = mid - 1;  // Target in left half
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int k;
    cout << "Enter k (no of elements to rotate): ";
    cin >> k;
    int target;
    cout << "Enter target: ";
    cin >> target;
    
    int x = rotate_sort(v, n, k, target);
    if(x != -1){
        cout << "Target found at index: " << x << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}