int n = s.size();
        int countZeros = 0;
        
        // Count zeros in the string (all can be included)
        for (char c : s) {
            if (c == '0') countZeros++;
        }
        
        int length = countZeros;   // start with all zeros included
        long long currentValue = 0;
        long long power = 1;       // represents 2^0 (rightmost bit)
        
        // Iterate from right to left (least significant bit)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                // Check if adding this bit exceeds k
                if (currentValue + power <= k) {
                    currentValue += power;
                    length++;
                }
                // else skip this '1'
            }
            
            power <<= 1;  // move to next bit (2^(bit position))
            
            // Optimization: if power > k, no need to continue
            if (power > k) break;
        }
        
        return length;
