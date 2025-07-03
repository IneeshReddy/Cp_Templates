#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
void Solve()
{                    
    int n;
    cin >> n;
 
    vector <vector <int>> g(n);
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
 
    vector <array <int, 2>> dp(n);
    vector <int> in(n), out(n);
    int T = 0;
 
    // dp[x][2] (0 -> nottake, 1 -> take that edge)
 
    auto dfs = [&] (int x, int c, auto && dfs) -> void {
        int cs = 0;
        for (auto i : g[x]) {
            if (i == c) {
                continue;
            }
            dfs (i, x, dfs);
            cs += max(dp[i][0], dp[i][1]);
        }
 
        dp[x][0] = max(dp[x][0], cs);
        for (auto i : g[x]) {
            if (i == c) {
                continue;
            }
            cs -= max(dp[i][0], dp[i][1]);
            cs += dp[i][0];
 
            dp[x][1] = max(dp[x][1], cs + 1);
 
            cs -= dp[i][0];
            cs += max(dp[i][0], dp[i][1]);
        }
    };
    dfs(0, -1, dfs);
    cout << max(dp[0][0], dp[0][1]) << '\n';
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