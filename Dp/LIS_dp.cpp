
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
const int N = 1e6 + 10;
pair<int,int> dp[N];
 
struct BIT{
//val, pos
pair<int,int> qry(int i){
   pair<int,int> ans = {0, 0};
   if(i == 0){
     return ans;
   }
   for(; i ; i -= i & (-i)){
     ans = max(ans, dp[i]);
   }
   return ans;
}
 
void upd(int i,int pos,int val){
     pair<int,int> p = {val, pos};
     for(; i < N; i += i & (-i)){
       dp[i] = max(dp[i], p);
     }
}
};
                     
void Solve(){
       int n;
       cin >> n;
       set<int> s;
       vector<int> v(n + 1);
       for(int i = 1; i <= n; i++){
         cin >> v[i];
         s.insert(v[i]);
       }            
       map<int,int> compress;
       int c = 2;
       for(auto i : s){
         compress[i] = c;
         c++;
       }
       for(int i = 1; i <= n; i++){
          v[i] = compress[v[i]];
       }
       BIT b; 
       int ans = 0;
       for(int i = 1; i <= n; i++){
            auto [x, y] = b.qry(v[i] - 1);
            ans = max(ans, x + 1);
            b.upd(v[i],i, x + 1);
       }
       cout << ans << '\n';
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