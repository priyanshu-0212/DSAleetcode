class Solution {
public:
    // Helper to check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    // Convert an integer to its base-k representation as a string
    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res = char('0' + (num % k)) + res;
            num /= k;
        }
        return res.empty() ? "0" : res;
    }

    // Generate palindromes based on a half string (mirror around center)
    vector<long long> generatePalindromes(int length) {
        vector<long long> result;
        int halfLen = (length + 1) / 2;
        int start = (halfLen == 1) ? 1 : pow(10, halfLen - 1);
        int end = pow(10, halfLen);

        for (int i = start; i < end; ++i) {
            string half = to_string(i);
            string full = half;
            if (length % 2 == 1) full.pop_back();  // Remove center for odd length
            reverse(half.begin(), half.end());
            full += half;
            result.push_back(stoll(full));
        }

        return result;
    }

    long long kMirror(int k, int n) {
        int length = 1;
        int count = 0;
        long long total = 0;

        while (count < n) {
            vector<long long> palindromes = generatePalindromes(length);
            for (long long num : palindromes) {
                string baseK = toBaseK(num, k);
                if (isPalindrome(baseK)) {
                    total += num;
                    if (++count == n) return total;
                }
            }
            ++length;
        }

        return total;
    }
};
