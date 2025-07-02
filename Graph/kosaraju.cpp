#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
                     
void Solve(){
     int n, m; cin >> n >> m;
 
     vector<int> g[n + 1], g1[n + 1];   
     for(int i = 0; i < m; i++){
         int x, y; cin >> x >> y;
         g[x].push_back(y);
         g1[y].push_back(x);
     } 
 
     vector<int> vis(n + 1);     
     vector<int> p;       
 
     function<void(int)> dfs = [&](int x){
         vis[x] = 1;
         for(auto i : g[x]){
             if(!vis[i]){
                dfs(i);
             }
         }
         p.push_back(x);
     };
 
 
     for(int i = 1; i <= n; i++){
         if(!vis[i]) dfs(i);
     }
 
     reverse(p.begin(), p.end());
     vector<int> T;
 
    
     function<void(int)> dfs1 = [&](int x){
         vis[x] = 0;
         for(auto i : g1[x]){
             if(vis[i]){
                dfs1(i);
             }
         }
 
         T.push_back(x);
     };
 
     vector<vector<int>> com;
 
     for(int i : p){
         T.clear();
         if(vis[i]){
            dfs1(i);
            com.push_back(T);
         }        
     }
 
     int nn = com.size();
     if(nn == 1){
        cout << "YES\n";
        return;
     } 
 
     cout << "NO\n";
     cout << com.back()[0] << ' ' << com[0][0] << '\n';
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