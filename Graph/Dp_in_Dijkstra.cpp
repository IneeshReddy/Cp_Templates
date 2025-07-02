#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
void Solve()
{                    
    int n, m;
    cin >> n >> m;
 
    vector <vector <pair <int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y, W;
        cin >> x >> y >> W;
        x--, y--;
        g[x].push_back({y, W});
    }                 
 
 
    vector <vector <int>> d(n, vector <int> (2, INF));
    d[0][0] = 0;
    d[0][1] = 0;
    priority_queue <array <int, 3>> pq;
    pq.push({0, 0, 0});
    pq.push({0, 0, 1});
    // dis, node, no of times
 
    while (!pq.empty()) {
        auto [dis, x, y] = pq.top();
        pq.pop();
 
        if (d[x][y] != -dis) continue;
        for (auto [i, W] : g[x]) {
            if (d[i][y] > d[x][y] + W) {
                d[i][y] = d[x][y] + W;
                pq.push({-d[i][y], i, y});
            }
            if (y == 0) {
                if (d[i][1] > d[x][0] + W / 2) {
                    d[i][1] = d[x][0] + W / 2;
                    pq.push ({-d[i][1], i, 1});
                }
            }
        }
    }
    cout << min(d[n - 1][1], d[n - 1][0]) << '\n';
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