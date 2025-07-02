#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
void Solve()
{                    
    int n, m;
    cin >> n >> m;
 
    vector <array <int, 3>> e(m);
    vector <vector <int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        e[i][0]--, e[i][1]--;
        g[e[i][0]].push_back(e[i][1]);
    }
 
    vector <int> d(n, -INF);
    d[0] = 0;
    // d[i] what is the max cost from 0 to i
    // So if we get a positive cycle from 1 to n then ans is -1
 
    vector <int> toclear;
    for (int i = 0; i < n; i++) {
        for (auto [x, y, W] : e) {
            if (d[y] < d[x] + W && d[x] != -INF) {
                if (i + 1 < n) {
                d[y] = d[x] + W;
                }
                else {
                    toclear.push_back(y);
                }
            }
        }
    }
 
    vector <int> vis(n);
 
    auto dfs = [&] (int x, auto && dfs) -> void {
        if (vis[x]) return;
        vis[x] = 1;
        for (auto i : g[x]) {
            if (!vis[i]) 
            dfs(i, dfs);
        }
    };
 
    for (auto x : toclear) dfs(x, dfs);
 
    cout << (vis[n - 1] ? -1 : d[n - 1]) << '\n';
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