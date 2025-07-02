class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        long long l = -1e10, r = 1e10, ans = 0;

        auto countLE = [&](long long x) -> long long {
            long long cnt = 0;
            for (int i = 0; i < n1; ++i) {
                if (nums1[i] < 0) {
                    auto it = lower_bound(nums2.begin(), nums2.end(), (long long)ceil(1.0 * x / nums1[i]));
                    cnt += nums2.end() - it;
                } else if (nums1[i] > 0) {
                    auto it = upper_bound(nums2.begin(), nums2.end(), (long long)floor(1.0 * x / nums1[i]));
                    cnt += it - nums2.begin();
                } else if (x >= 0) {
                    cnt += n2;
                }
            }
            return cnt;
        };

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (countLE(mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
