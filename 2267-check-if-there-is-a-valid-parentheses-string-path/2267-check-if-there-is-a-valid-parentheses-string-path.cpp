class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>>& grid, int i, int j, int open) {

        // Process current cell
        if (grid[i][j] == '(')
            open++;
        else
            open--;

        // Invalid prefix
        if (open < 0)
            return false;

        // Bottom-right
        if (i == m - 1 && j == n - 1)
            return open == 0;

        // Remaining cells cannot close all opened brackets
        int remaining = (m - 1 - i) + (n - 1 - j);

        if (open > remaining)
            return false;

        if (dp[i][j][open] != -1)
            return dp[i][j][open];

        bool ans = false;

        // Down
        if (i + 1 < m)
            ans = dfs(grid, i + 1, j, open);

        // Right
        if (!ans && j + 1 < n)
            ans = dfs(grid, i, j + 1, open);

        return dp[i][j][open] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Valid string must start with '('
        if (grid[0][0] != '(')
            return false;

        // Valid string must end with ')'
        if (grid[m - 1][n - 1] != ')')
            return false;

        dp.assign(
            m,
            vector<vector<int>>(n, vector<int>(m + n, -1))
        );

        return dfs(grid, 0, 0, 0);
    }
};