#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
                     
void Solve()
{                    
    int n;
    cin >> n;
 
    vector <int> v(n);
    int cs = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cs += v[i];
    }               
 
    vector <vector <int>> dp(n, vector <int> (n, -INF));  
    // dp[i][j] from i to j what is the max possible val of Alice - Bob
 
    for (int l = n - 1; l >= 0; l--) {
        dp[l][l] = v[l];
        for (int r = l + 1; r < n; r++) {
            dp[l][r] = max(dp[l][r], v[l] - dp[l + 1][r]);
            dp[l][r] = max(dp[l][r], v[r] - dp[l][r - 1]);
        }
    }
 
    cout << (dp[0][n - 1] + cs) / 2 << '\n';
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