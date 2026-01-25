class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros = 0, ones = 0;

        // Count student preferences
        for (int s : students) {
            if (s == 0) {
                zeros++;
            } else {
                ones++;
            }
        }

        // Process sandwiches from top to bottom
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0) {
                if (zeros > 0) {
                    zeros--;
                } else {
                    break;
                }
            } else { // sandwiches[i] == 1
                if (ones > 0) {
                    ones--;
                } else {
                    break;
                }
            }
        }

        // Students who could not eat
        return zeros + ones;
    }
};
