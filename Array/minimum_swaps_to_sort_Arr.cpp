#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSwaps(vector<int>& arr) {
    int n = arr.size(); 
    int swaps = 0;
    
    vector<pair<int, int>> elementsWithIndex;
    for(int i = 0; i < n; i++) {
        elementsWithIndex.push_back({arr[i], i});
    }
    
    sort(elementsWithIndex.begin(), elementsWithIndex.end());
    
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(visited[i] || elementsWithIndex[i].second == i) {
            continue;
        }
        
        int current = i;
        int cycleSize = 0;
        
        while(!visited[current]) {
            visited[current] = true;
        
            current = elementsWithIndex[current].second;
            cycleSize++;
        }
        
        swaps += (cycleSize - 1);
    }
    
    return swaps;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << "Minimum swaps: " << minSwaps(arr) << endl;
    return 0;
}