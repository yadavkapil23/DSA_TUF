// Maximum water in container
#include <iostream>
#include <vector>
using namespace std;

int container(vector<int>& v) {
    int left = 0;  //starting from first wall.
    int right = v.size() - 1; //start from the last wall.
    int maxarea = 0; //mmax size found till now.
    
    while (left < right) {
        int left_height = v[left]; //find the height of left wall.
        int right_height = v[right]; //find the height of right wall.
        
        int width = right - left; //distance between the two walls
        int water_ht = min(left_height, right_height); //Water height is limited by the shorter wall (water would spill over)
        //if one wall is 2 or another is 5 , then it will hold upto a height of 2 only after that water will splill , so same here it can overflow.
        //so we choose the min value as it will be the limit upto which it can be filled.
        
        int area = water_ht * width; //find area.
        
        maxarea = max(maxarea, area); //maximum area.
        
        if (left_height < right_height) { //If left wall is shorter, move left pointer right (try a taller left wall)
            left++;
        } else {
            right--; //if right is shorter move to the left side.
        }
    }
    
    return maxarea;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int ans = container(v);
    cout << "Maximum water area = " << ans << endl;
}
