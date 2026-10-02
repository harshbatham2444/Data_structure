class Solution {
public:
    vector<string> ans;

    void solve(string s, int open, int close, int n) {

        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // '(' add kar sakte hain
        if (open < n) {
            solve(s + '(', open + 1, close, n);
        }

        // ')' tabhi add karenge jab
        // open > close ho
        if (close < open) {
            solve(s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};