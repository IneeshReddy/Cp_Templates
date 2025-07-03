#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
 
struct segTree {
 
    int n;
    vector <int> seg;
    segTree (int n) : n(n), seg(4 * n) {} 
 
    
    int merge (int x, int y) {
        return max(x, y);
    }
 
    void upd (int l, int r, int p, int i, int v) {
        if (l > p || r < p) return;
        if (l == r) {
            seg[i] = v;
            return;
        }
 
        int m = (l + r) / 2;
        upd (l, m, p, 2 * i, v);
        upd (m + 1, r, p, 2 * i + 1, v);
        seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
    }
 
    int qry (int l, int r, int lx, int rx, int i) {
        if (l > rx || r < lx) return 0;
        if (l >= lx && r <= rx) {
            return seg[i];
        }
        int m = (l + r) / 2;
        return merge(qry(l, m, lx, rx, 2 * i), qry(m + 1, r, lx, rx, 2 * i + 1));
    }
 
    void upd (int p, int v) {
        upd (0, n - 1, p, 1, v);
    }
 
    int qry (int l, int r) {
        if (l > r) return 0;
        return qry(0, n - 1, l, r, 1);
    }
};
                     
void Solve()
{                    
   int n;
   cin >> n;
 
   vector <int> left(n, -1), right(n, n);
   vector <int> v(n);
   vector <pair <int, int>> p;
   stack <int> st;
   for (int i = 0; i < n; i++) {
    cin >> v[i];
    p.push_back({v[i], i});
    while (!st.empty() && v[st.top()] < v[i]) {
        st.pop();
    }
 
    if (!st.empty())
    left[i] = st.top();
 
    st.push(i);
   }
 
   while (!st.empty()) st.pop();
 
   for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && v[st.top()] < v[i]) {
        st.pop();
    }
 
    if (!st.empty()) {
        right[i] = st.top();
    }
 
    st.push(i);
   }
 
   sort(p.begin(), p.end());
   segTree dp(n);
   int ans = 0;
   // dp[i] max possible mountains that can be covered if we start at ith index
   for (auto [_, i] : p) {
    int x = left[i] + 1, y = right[i] - 1;
    int z = max(dp.qry(x, i - 1), dp.qry(i + 1, y)) + 1;
    dp.upd(i, z);
    ans = max(ans, z);
   }
 
   cout << ans << '\n';
}
                     
int32_t main()
{                              
   auto begin = std::chrono::high_resolution_clock::now();
   ios_base::sync_with_stdio(0);
   cin.tie(0);
                             
   int T = 1;
//    cin >> T;
                              
   for(int i = 1; i <= T; i++) {
       //std::cout << "Case #" << i << ": ";
       Solve();
   }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}