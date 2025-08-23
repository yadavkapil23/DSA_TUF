#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(12);
    v.push_back(30);
    v.push_back(56);
    v.push_back(10);

    cout<<"Finding : "<<binary_search(v.begin(),v.end(),30);


    cout<<"Lower Bound : "<<lower_bound(v.begin(),v.end(),12) - v.begin()<<endl;
    cout<<"Upper Bound : "<<upper_bound(v.begin(),v.end(),12) - v.begin()<<endl;

    int a=99;
    int b=34;
    cout<<"Maximum : "<<max(a,b)<<endl;
    cout<<"Minimum : "<<min(a,b)<<endl;

    cout<<"Before Swapping : "<<a<<b<<endl;
    swap(a,b);
    cout<<"After Swapping : "<<a<<b<<endl;

    string str= "abcd";
    reverse(str.begin(),str.end());
    cout<<"String : "<<str<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    
    cout<<"After Rotation : "<<endl;
    for(int i:v){
        cout<<i<<endl;
    }

}