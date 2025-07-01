class Solution {
public:
    int possibleStringCount(string word) {
         int ans = 1; // Initialize the answer to 1
                 for (int i = 1; i < word.size(); ++i) {
                             if (word[i] == word[i - 1]) {
                                             ++ans; // Increment the answer for each consecutive duplicate character
                                                         }
                                                                 }
                                                                         return ans;
    }
};
