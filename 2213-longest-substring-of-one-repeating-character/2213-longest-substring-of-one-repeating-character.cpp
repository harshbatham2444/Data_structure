class Solution {
public:
    struct Node {
        int len = 0;
        int pref[26] = {};
        int suff[26] = {};
        int best[26] = {};
        int mx = 0;
    };

    vector<Node> tree;
    string s;

    Node merge(Node &L, Node &R) {
        Node res;
        res.len = L.len + R.len;

        for (int c = 0; c < 26; c++) {
            res.pref[c] = L.pref[c];

            if (L.pref[c] == L.len)
                res.pref[c] += R.pref[c];

            res.suff[c] = R.suff[c];

            if (R.suff[c] == R.len)
                res.suff[c] += L.suff[c];

            res.best[c] = max(L.best[c], R.best[c]);
            res.best[c] = max(res.best[c],
                              L.suff[c] + R.pref[c]);

            res.mx = max(res.mx, res.best[c]);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].len = 1;

            int c = s[l] - 'a';
            tree[node].pref[c] = 1;
            tree[node].suff[c] = 1;
            tree[node].best[c] = 1;
            tree[node].mx = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node] = Node();

            tree[node].len = 1;

            int c = ch - 'a';
            tree[node].pref[c] = 1;
            tree[node].suff[c] = 1;
            tree[node].best[c] = 1;
            tree[node].mx = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, ch);
        else
            update(node * 2 + 1, mid + 1, r, idx, ch);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].mx);
        }

        return ans;
    }
};