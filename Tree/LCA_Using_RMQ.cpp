#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// Optimised version of LCA
// Usually LCA takes O(log n) but now we are using RMQ so it will take O(1)
 
const int N = 4e5 + 1;
int fst[N], d[N], n, q;
vector <vector <int>> g;
vector <int> p;
 
void dfs (int x, int c = -1) {
    
    fst[x] = (int)p.size();
    p.push_back(x);
    
    for (auto i : g[x]) {
        if (i == c) {
            continue;
        }
        d[i] = d[x] + 1;
        dfs (i, x);
        p.push_back(x);
    }
}
 
 
 
                     
void Solve()
{                    
    cin >> n >> q;
 
 
    g.resize(n);
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);  
    }
 
    dfs(0);
 
    vector <vector <int>> dp((int)p.size(), vector <int> (20, INF));
 
    for (int i = 0; i < p.size(); i++) {
        dp[i][0] = d[p[i]];
    }
 
    
 
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i + (1LL << j) <= (int)p.size(); i++) {
            int cur = dp[i][j - 1];
            int nxt = i + (1LL << (j - 1));
            dp[i][j] = min(dp[i][j - 1], dp[nxt][j - 1]);
        }
    }
 
    auto query = [&] (int i, int j) -> int {
        if (i > j) swap(i, j);
        int len = j - i + 1;
        int dis = log2(len);
 
        return min(dp[i][dis], dp[j - (1LL << dis) + 1][dis]);
    };    
 
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
 
        int z = query(fst[x], fst[y]);
        cout << d[x] + d[y] - 2 * z << '\n';
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