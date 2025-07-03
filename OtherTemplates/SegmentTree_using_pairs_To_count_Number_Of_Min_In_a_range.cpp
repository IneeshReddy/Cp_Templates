#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e9;

class SegTree
{
public:
    vector<pair<int, int>> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    pair<int, int> combine(pair<int, int> a, pair<int, int> b)
    {
        pair<int, int> p;
        p.first = min(a.first, b.first);
        if (a.first == b.first)
        {
            p.second = a.second + b.second;
        }
        else
        {
            if (a.first < b.first)
                p.second = a.second;
            else
                p.second = b.second;
        }
        return p;
    }
    void build(int ind, int low, int high, vector<pair<int, int>> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = combine(seg[(2 * ind + 1)], seg[(2 * ind + 2)]); // Fix the opertation according to the question
    }

    pair<int, int> query(int ind, int low, int high, int l, int r, vector<pair<int, int>> &arr)
    {
        // l r low high
        // low high l r
        if (r < low || l > high)
            return {inf, 1}; // Fix the return value according to the question

        // low l r high
        if (l <= low && r >= high)
            return seg[ind];

        int mid = (low + high) / 2;
        pair<int, int> left = query(2 * ind + 1, low, mid, l, r, arr);
        pair<int, int> right = query(2 * ind + 2, mid + 1, high, l, r, arr);
        return combine(left, right); // Fix the return value according to the question
    }
    void update(int ind, int low, int high, int index, int val, vector<pair<int, int>> &arr)
    {
        if (low == high)
        {
            seg[ind].first = val;
            return;
        }
        int mid = (low + high) / 2;
        if (index <= mid)
        {
            update(2 * ind + 1, low, mid, index, val, arr);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, index, val, arr);
        }
        seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]); // Fix the return value according to the question
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = make_pair(x, 1);
    }
    SegTree seg(n);
    seg.build(0, 0, n - 1, v);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int index, val;
            cin >> index >> val;
            seg.update(0, 0, n - 1, index, val, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            r--;
            pair<int, int> p = seg.query(0, 0, n - 1, l, r, v);
            cout << p.first << " " << p.second << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin>>t;
    // while(t--)
    solve();
}