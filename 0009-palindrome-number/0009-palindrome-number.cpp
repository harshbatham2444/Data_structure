class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long int original = x;
        long long int rev = 0;

        while (x != 0) {
            long long int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return original == rev;
    }
};