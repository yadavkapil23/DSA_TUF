class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        if (v.empty()) return 0;

        int k = 1; // index for unique elements

        for (int i = 1; i < v.size(); i++) {
            if (v[i] != v[i - 1]) {
                v[k] = v[i];
                k++;
            }
        }

        return k;
    }
};
