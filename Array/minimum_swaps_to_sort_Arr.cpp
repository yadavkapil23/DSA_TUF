#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSwaps(vector<int>& arr) {
    int n = arr.size(); 
    int swaps = 0;
    
    vector<pair<int, int>> elementsWithIndex; //creating a pair to store the elements with the value and their index.
    for(int i = 0; i < n; i++) { 
        elementsWithIndex.push_back({arr[i], i}); //entering the value and the index number.
    }
    
    sort(elementsWithIndex.begin(), elementsWithIndex.end()); //sort the elements  , like which should come first , sort by elements , not by index.
    
    vector<bool> visited(n, false); //create a vector visited to store that , whether we have visited any element or not , initialise it by 0.
    
    for(int i = 0; i < n; i++) {
        if(visited[i] || elementsWithIndex[i].second == i) { //if the current element is visited or it has been at correct position already skip it.
            continue;
        }
        
        int current = i;  //starts a new cycle from current index.
        int cycleSize = 0; //initializes the size of the cycle to zero.
        
        while(!visited[current]) { //continues until the current element is visited.
            visited[current] = true; //marks the current element as visited.
        
            current = elementsWithIndex[current].second; //moves to the next index in the cycle.
            cycleSize++; //increments the length of the cycle.
        }
        
        swaps += (cycleSize - 1);  //adds the number of the swaps required for the current cycle.
    }
    
    return swaps;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << "Minimum swaps: " << minSwaps(arr) << endl;
    return 0;
}