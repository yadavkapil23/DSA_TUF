int searchx(vector<int>&v,int k){
    int n = v.size();
    int left = 0;
    int right = n-1;
    int ans = n;
    while(left <= right){
        int mid = left + (right-left)/2;

        if(v[mid] >= k){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return ans;

    //here we have implemented the lower bound and also we have given the index to insert an element there.
}