#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Normal Kadane's Algorithm (max subarray sum)
int Kadane(vector<int>& v, int n) {
    int sum = 0;
    int maxi = v[0];
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (sum > maxi) {
            maxi = sum;
        }
        if (sum < 0) {
            sum = 0; // restart from current element
        }
    }
    return maxi;
}
int maxCircularSubarraySum(vector<int>& v, int n) {
    int max_normal = Kadane(v, n);

    //If max_normal is negative, it means all elements in the array are negative. In this case, the maximum sum is simply the single largest 
    if (max_normal < 0) return max_normal;

    //Sum of a wrapping subarray is equal = (Total Sum of the Array) - (Sum of the Elements Not in the Subarray)

    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += v[i];  //this calculates the total sum of the subarray.
        v[i] = -v[i]; // invert array to find min sum using Kadane
    }


    //CORE :  sum(original) = - sum(inverted)

    int min_subarray_sum = -Kadane(v, n); //pass the inverted array in Kadane to find the maximum sum in that. , -ve sign , that’s the minimum subarray sum of the original array
    int max_circular = total_sum - min_subarray_sum;

    //answer is max of normal and circular
    return max(max_normal, max_circular);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Maximum Circular Subarray Sum = " 
         << maxCircularSubarraySum(v, n) << endl;

    return 0;
}
