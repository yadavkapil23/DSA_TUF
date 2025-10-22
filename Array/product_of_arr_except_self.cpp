#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n, 1);

    // Step 1: Calculate left products
    // output[i] will temporarily store the product of all numbers to the left of i
    for (int i = 1; i < n; i++) {
        output[i] = output[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply by right products using a running variable
    int rightProduct = 1; // no numbers to the right of last element
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= rightProduct;  // multiply left product with right product
        rightProduct *= nums[i];    // update right product for next iteration
    }

    return output;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
