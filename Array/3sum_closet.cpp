#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sum_closet(vector<int>&v,int n,int k){
//we need three values to get the sum of those.
//the first one would be from left , another one is current , and last one is right.
sort(v.begin(),v.end());
int sum = 0;
int bestsum = v[0] + v[1] + v[2];
for(int i=0 ; i<n-2 ; i++){
    for(int j=i+1 ; j<n-1 ; j++){
        int left = j+1;
        int right = n-1;
        while(left < right){
            sum = v[i] + v[left] + v[right];
        if(sum == k){
            cout<<"values are : "<<v[i]<<"and "<<v[left]<<" and : "<<v[right];
            left++;
            right--;
        }
                else if(sum < k){
            left++;
        }
        else if(sum>k){
            right--;
        }
        if(left < right && v[left] == v[left+1]){
            left++;
        }
        if(left < right && v[right] == v[right-1]){
            right--;
        }
        if (abs(sum - k) < abs(bestsum - k)) {
    bestsum = sum;
}
        }
    }
        int diff = (sum - k);
}
return bestsum;

}
int main(){
int n;
cin>>n;
int k;
cout<<"enter k : ";cin>>k;
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
int ans = sum_closet(v, n, k);
cout << "Closest sum: " << ans << "\n";
}