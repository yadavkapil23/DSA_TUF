#include<iostream>
#include<vector>
#include<algorithm> // Needed for max()
using namespace std;

int main(){
    int size;
    cout<<"enter size : ";cin>>size;
    vector<int> v(size);

    for(int i=0 ; i<size ; i++){
        cin>>v[i];
    }

    // int size = v.size();
    int K = 6;    // target sum ,we want to find subarrays that add up to 6.
    int len = 0;  // len to store the length of the longest subarray , initilise it with the zero as we haven't found any elements so far

    // Core Logic
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            //Together, i and j define one unique subarray. For example, when i=1 and j=3, you are looking at the subarray {2, 3, 4}.
            int sum = 0;

            // arr = {1,2,3,4};
            // the possible subarr = {1},{1,2},{1,2,3},{1,2,3,4} / {2},{2,3},{2,3,4} / {3},{3,4} / {4};
            // i will be pointing to the single element like 1,2,3 and j will be travesring to all elements left to make subarray like - 1,2 / 1,2,3 / 1,2,3,4.

            
            for(int k = i; k <= j; k++){ //to add up the numbers in the current subarray defined by i and j
                sum += v[k]; //takes the number at the current position k in the list and adds it to the sum.
            }
            if(sum == K){ 
                
                len = max(len, j - i + 1);
                //compares this new length to the value already stored in len and keeps whichever one is bigger. This ensures len always holds the "record" for the longest length found so far.
            }
        }
    }

    cout << "Answer is : " << len << endl; // For K=6, this should output 3 (for subarray {1, 2, 3})
    return 0;
}