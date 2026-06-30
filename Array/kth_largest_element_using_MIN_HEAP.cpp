#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
priority_queue<int, vector<int>, greater<int>> pq;

vector<int> nums;
int k;
for (int x : nums) {
    pq.push(x);

    if (pq.size() > k)
        pq.pop();
}

return pq.top();

}