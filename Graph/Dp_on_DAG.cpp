#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
                     
void Solve(){
     int n, m;
     cin >> n >> m;
     
     vector<int> g[n + 1];
     vector<int> g1[n + 1];
     for(int i = 0; i < m; i++){
         int x, y;
         cin >> x >> y;
         g[x].push_back(y);
     }
 
     vector<int> dp(n + 1, -INF);
     dp[n] = 1;
     vector<int> par(n + 1);
     vector<int> vis(n + 1);
     function<void(int, int)> dfs = [&](int x, int c){
         vis[x] = 1;
         for(auto i : g[x]){
            if(i != c && !vis[i]){
                dfs(i, x);
            }
            if(dp[i] != -INF){
                if(dp[x] < dp[i] + 1){
                    par[x] = i;
                    dp[x] = dp[i] + 1;
                }
            }
         }
     };  
     dfs(1, -1);
     if(dp[1] == -INF){
        cout << "IMPOSSIBLE\n";
        return;
     }
 
     
     cout << dp[1] << '\n';
     int j = 1;
     cout << j << ' ';
     while(j != n){
        j = par[j];
        cout << j << ' ';
     }
 
}
                     
                     
int32_t main(){
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