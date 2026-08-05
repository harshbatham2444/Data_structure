class Solution {
public:
    int start = 0, maxLen = 1;

    void expand(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i);       // Odd length
            expand(s, i, i + 1);   // Even length
        }

        return s.substr(start, maxLen);
    }
};