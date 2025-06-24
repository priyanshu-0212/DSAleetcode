vector<int> result;
    int n = nums.size();

    for (int j = 0; j < n; ++j) {
        if (nums[j] == key) {
            int start = max(0, j - k);
            int end = min(n - 1, j + k);
            for (int i = start; i <= end; ++i) {
                result.push_back(i);
            }
        }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
