#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int needdays(vector<int>& weights, int capacity) {
    int days_needed = 1;
    int load = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (load + weights[i] > capacity) {
            days_needed++;
            load = weights[i];
        } else {
            load += weights[i];
        }
    }
    return days_needed;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int daysreq = needdays(weights, mid);
        if (daysreq <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}