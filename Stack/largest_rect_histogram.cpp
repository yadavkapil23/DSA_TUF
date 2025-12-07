#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int largest_historgram(vector<int> &v){
    int n = v.size();
    int area;
    int max_area=1;
    vector<int> areas;
    for(int i=0 ; i<n; i++){
        int height = v[i];
        int left = i;
        while(left>0 && v[left-1] > height){
            left--;
        }
        int right = i;
        while(right < n - 1 && v[right + 1] >= height) {
            right++;
        }
        int width = right-left+1;
        area = height * width;
        max_area = max(max_area,area);
    }
    return max_area;
}
int main(){
    vector<int> v = {4,2,3};
    int ans = largest_historgram(v);
    cout<<ans<<endl;
    return 0;
}
