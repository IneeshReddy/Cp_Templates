#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                   
                     
void Solve(){
       int n;
       cin >> n;
 
       vector<int> dia(n + 1);
       vector<int> adj[n + 1];
       for(int i = 0; i + 1 < n; i++){
          int x, y;
          cin >> x >> y;
          adj[x].push_back(y);
          adj[y].push_back(x);
       }
 
       vector<int> H(n + 1);
 
       function<void(int, int)> dfs = [&](int x, int c){
         vector<int> v;
         for(auto i : adj[x]){
             if(i == c){
                 continue;
             }
             dfs(i, x);
             H[x] = max(H[x], H[i] + 1);
             dia[x] = max(dia[x], dia[i]);
             v.push_back(H[i]);
         }
         if(v.empty()){
            return;
         }
         sort(v.rbegin(), v.rend());
         if(v.size() == 1){
            dia[x] = max(dia[x], v[0] + 1);
         }
         else{
            dia[x] = max(dia[x], v[0] + v[1] + 2);
         }
       };
       dfs(1, -1);
       cout << dia[1] << '\n';       
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