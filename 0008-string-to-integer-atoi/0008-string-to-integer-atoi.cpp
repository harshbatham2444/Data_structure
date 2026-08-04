class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long ans = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};