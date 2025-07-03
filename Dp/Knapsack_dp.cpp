#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
                     
void Solve(){
       int n, x;
       cin >> n >> x;
       vector<int> dp(x + 1, INF); 
       vector<int> v(n);
       for(int i = 0; i < n; i++) cin >> v[i];
       dp[0] = 0;
       for(int i = 0; i < n; i++){
          for(int j = 0; j <= x; j++){
             if(j + v[i] <= x){
              dp[j + v[i]] = min(dp[j + v[i]], dp[j] + 1);
             }
          }
       } 
 
       cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
}
                     
                     
int32_t main(){
   auto begin = std::chrono::high_resolution_clock::now();
   ios_base::sync_with_stdio(0);
   cin.tie(0);
                             
                             
   int T = 1;
  //  cin >> T;
   for(int i = 1; i <= T; i++) {
       //std::cout << "Case #" << i << ": ";
       Solve();
   }
                             
                             
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}