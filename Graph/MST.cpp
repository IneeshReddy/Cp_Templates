#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
struct DSU {
    vector <int> rank, p;
    int n;
    int cnt;
    void in_it (int nn) {
        n = nn;
        rank.resize(n);
        p.resize(n);
        cnt = n;
 
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
 
    int get(int x) {
        return p[x] = (p[x] == x ? x : get(p[x]));
    }
 
    bool same (int x, int y) {
        return get(x) == get(y);
    }
 
    void merge (int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        // Merge case
        cnt--;
 
        if (rank[x] > rank[y]) swap (x, y);
        p[x] = y;
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};
 
                     
void Solve()
{                    
   int n, m;
   cin >> n >> m;
 
   vector < array <int, 3>> g(m);
   for (int i = 0; i < m; i++) {
    cin >> g[i][0] >> g[i][1] >> g[i][2];
    g[i][0]--;
    g[i][1]--;
   }          
 
   sort (g.begin(), g.end(), [&](array <int, 3> a1, array <int, 3> a2){
   return a1[2] < a2[2];
   });
 
   DSU d;
   d.in_it(n);
 
   int ans = 0;
   for (auto [x, y, W] : g) {
    if (d.same(x, y)) continue;
    d.merge(x, y);
    ans += W;
   }
 
   if (d.cnt == 1) {
    cout << ans << '\n';
   }
   else {
    cout << "IMPOSSIBLE\n";
   }
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