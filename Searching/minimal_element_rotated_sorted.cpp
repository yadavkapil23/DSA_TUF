class Solution{
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        // If left half is sorted
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // If right half is sorted
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    
    return ans;
}
};