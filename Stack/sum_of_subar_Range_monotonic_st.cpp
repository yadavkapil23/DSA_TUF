long long subranges(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftMin(n), rightMin(n), leftMax(n), rightMax(n);
    stack<int> st;

    // For minimum: next smaller (right)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i])
            st.pop();
        leftMin[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();

    // For minimum: previous smaller or equal (left)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();
        rightMin[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }
    while (!st.empty()) st.pop();

    // For maximum: next greater (right)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i])
            st.pop();
        leftMax[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();

    // For maximum: previous greater or equal (left)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();
        rightMax[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long maxCnt = (long long)leftMax[i] * rightMax[i];
        long long minCnt = (long long)leftMin[i] * rightMin[i];
        ans += nums[i] * (maxCnt - minCnt);
    }
    return ans;
}
