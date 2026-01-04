class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        int n = v.size();
        sort(v.begin(), v.end());

        int closestsum = v[0] + v[1] + v[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = v[i] + v[left] + v[right];

                if (abs(sum - target) < abs(closestsum - target)) {
                    closestsum = sum;
                }

                if (sum == target) {
                    return sum;
                } 
                else if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return closestsum;
    }
};
