#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
                     
void Solve(){
       int n, m; cin >> n >> m;
       vector<pair<int,int>> g[n + 1];
       for(int i = 0; i < m; i++){
         int x, y, W;
         cin >> x >> y >> W;
         g[x].push_back(make_pair(y, W));
       }              
 
       auto dijs = [&](){
         vector<int> d(n + 1, INF);
         d[1] = 0;
 
         priority_queue<pair<int,int>> pq;
         pq.push({0, 1});
 
         while(!pq.empty()){
              auto [u, x] = pq.top();
              pq.pop();
 
              if(-u != d[x]) continue;
              for(auto [i, W] : g[x]){
                 if(d[x] + W < d[i]){
                    d[i] = d[x] + W;
                    pq.push({-d[i], i});
                 }
              }
         }
 
         return d;
       };
 
       vector<int> d = dijs();
       for(int i = 1; i <= n; i++){
        cout << d[i] << " \n"[i == n];
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
    std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}