#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // Stores indices
        int total_water = 0;
        int current = 0;
        
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                // 1. Get Bottom
                int bottom = st.top();
                st.pop();

                // 2. Check Left Wall
                if (st.empty()) {
                    break;
                }
                
                // 3. Get Left Wall
                int left = st.top();
                
                // 4. Calculate
                int width = current - left - 1;
                int bounded_height = min(height[left], height[current]) - height[bottom];
                
                total_water += width * bounded_height;
            }
            
            st.push(current);
            current++;
        }
        return total_water;
    }
};