//LOGIC - 
// 1.ROTATE EACH ROW BY 90 DEGREE TO RIGHT.
// 2.REVERSE EACH ROW
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void matrix(vector<vector<int>>& v, int n){ // Correct: vector of vectors{
    //rotating the matrix by 90 degrees towards the right.
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            swap(v[i][j],v[j][i]);
        }
    }
    //now reversing.
    for(int i=0 ; i<n ; i++){
        reverse(v[i].begin(),v[i].end());
    }
}
int main(){
    int n;
    cin>>n;
     vector<vector<int>> v(n, vector<int>(n));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin>>v[i][j];
        }
    }

        matrix(v,n);

        for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }


}