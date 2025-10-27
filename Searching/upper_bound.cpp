int searchx(vector<int>&v,int k){
    int n = v.size();
    int inserted = 9;
    int left = 0;
    int right = n-1;
    int ans = n;
    while(left <= right){
        int mid = left + (right-left)/2;

        if(v[mid] > k){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return ans;
}