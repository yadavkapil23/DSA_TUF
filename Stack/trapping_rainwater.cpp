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
            while (!st.empty() && height[current] > height[st.top()]) { //keep popping until we find an element that is not bigger or equal to right element.
                int bottom = st.top();
                st.pop();
                // 2. Check Left Wall
                if (st.empty()) {
                    break;
                }
                
                // 3. Get Left Wall
                int left = st.top();
                
                // 4. Calculate
                int width = current - left - 1; // -1 is here , just to exclude the walls while counting the distance and only include the distance or units between them.
                int bounded_height = min(height[left], height[current]) - height[bottom];
                
                total_water += width * bounded_height;
            }
            
            st.push(current);
            current++;
        }
        return total_water;
    }
};