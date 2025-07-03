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
 
    vector <int> sub(n), d(n), pr(n);
    vector <int> ans(n);
 
    auto rec = [&] (int x, int c, auto && rec) -> void {
        sub[x] = 1;
        for (auto i : g[x]) {
            if (i == c) {
                continue;
            }
            d[i] = d[x] + 1;
            rec(i, x, rec);
            pr[x] += pr[i];
            sub[x] += sub[i];
        }
        pr[x] += d[x];
    };
    rec (0, -1, rec);
    ans[0] = pr[0];
    int cs = pr[0];
 
    auto dfs = [&] (int x, int c, auto && dfs) -> void {
        for (auto i : g[x]) {
            if (i == c) {
                continue;
            }
 
            int org = pr[x], org1 = pr[i];
            pr[x] -= pr[i];
            pr[x] += (sub[x] - sub[i]);
            pr[i] -= sub[i];
            pr[i] += pr[x];
 
            int sf = sub[i];
            sub[i] = sub[x];
            sub[x] -= sf;
            
            ans[i] = pr[i];
            dfs(i, x, dfs);
            
            sub[i] = sf;
            sub[x] += sf;
 
            pr[i] = org1;
            pr[x] = org;
        }
    };
    
    dfs (0, -1, dfs);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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